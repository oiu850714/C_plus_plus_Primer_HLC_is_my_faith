#include <set>
#include <string>

class Folder;

class Message;

class Folder {
public:
  void addMsg(const Message *);
  void remMsg(const Message *);
};

class Message {
  friend class Folder;

public:
  // folders is implicitly initialized to the empty set
  explicit Message(const std::string &str = "") : contents(str) {}
  // copy control to manage pointers to this Message
  Message(const Message &);            // copy constructor
  ~Message();                          // destructor
  Message &operator=(const Message &); // copy assignment
  // add/remove this Message from the specified Folder’s set of messages
  void save(Folder &);
  void remove(Folder &);

private:
  std::string contents;       // actual message text
  std::set<Folder *> folders; // Folders that have this Message
  // utility functions used by copy constructor, assignment, and destructor
  // add this Messageto the Folders that point to the parameter
  void add_to_Folders(const Message &);
  // remove this Message from every Folder in folders
  void remove_from_Folders();
};

void Message::save(Folder &f) {
  folders.insert(&f); // add the given Folder to our list of Folders
  f.addMsg(this);     // add this Message to f’s set of Messages
}
void Message::remove(Folder &f) {
  folders.erase(&f); // take the given Folder out of our list of Folders
  f.remMsg(this);    // remove this Message to f’s set ofMessages
}

// add this Message to Folders that point to m
void Message::add_to_Folders(const Message &m) {
  for (auto f : m.folders) // for each Folder that holds m
    f->addMsg(this);       // add a pointer to this Message to that Folder
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
  add_to_Folders(m); // add this Messageto the Foldersthat point to m
}

void Message::remove_from_Folders() {
  for (auto f : folders) // for each pointer in folders
    f->remMsg(this);     // remove this Message from that Folder
  folders.clear();
  // no Folder points to this Message
}

Message::~Message() { remove_from_Folders(); }

Message &Message::operator=(const Message &rhs) {
  if (this != &rhs) {        // self-assigment check is necessary
                             // while remove_from_Folders() do folders.clear()
    remove_from_Folders();   // update existing Folders
    contents = rhs.contents; // copy message contents from rhs
    folders = rhs.folders;   // copy Folder pointers from rhs
    add_to_Folders(rhs);     // add this Message to those Folders
  }
  return *this;
}