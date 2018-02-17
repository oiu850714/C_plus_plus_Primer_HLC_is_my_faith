#ifndef _13_36_h_
#define _13_36_h_

#include <set>
#include <string>

// I refer to:
// https://github.com/huangmingchuan/Cpp_Primer_Answers/blob/master/ch13/exercise13_34.h

class Folder;

class Message {
  friend class Folder;
  friend void swap(Message &, Message &);
  friend void swap(Folder &lhs, Folder &rhs);

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

  // debug utility
  void print_debug();

private:
  // below two members are ex 13.37
  inline void addFolder(Folder *f) { folders.insert(f); }
  inline void remFolder(Folder *f) { folders.erase(f); }

  std::string contents;       // actual message text
  std::set<Folder *> folders; // Folders that have this Message
  // utility functions used by copy constructor, assignment, and destructor
  // add this Messageto the Folders that point to the parameter
  void add_to_Folders(const Message &);
  // remove this Message from every Folder in folders
  void remove_from_Folders();
};

void swap(Message &, Message &);

class Folder {
  friend class Message;
  friend void swap(Folder &lhs, Folder &rhs);
  friend void swap(Message &lhs, Message &rhs);

public:
  Folder() = default;
  Folder(const Folder &folder);
  Folder &operator=(const Folder &);

  // debug utility
  void print_debug();

private:
  void addMsg(Message *msg) { messages.insert(msg); }
  void remMsg(Message *msg) { messages.erase(msg); }
  // above two should be private, it cannot be directly called because the
  // Message object to which parameter points will not update it's folders
  // member

  std::set<Message *> messages;
  void add_to_Messages(const Folder &); // copy-control utility
  void remove_from_Messages();          // copy-control utility
};

void swap(Folder &lhs, Folder &rhs);

#endif