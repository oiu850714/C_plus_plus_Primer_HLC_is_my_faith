#include <iostream>
#include <set>
#include <string>

#include "13.36.h"

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
  add_to_Folders(m); // add this Messageto the Folders that point to m
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

void Message::print_debug() { std::cout << contents << std::endl; }

Folder::Folder(const Folder &folder) : messages(folder.messages) {
  add_to_Messages(folder);
}

void Folder::add_to_Messages(const Folder &folder) {
  for (auto message : folder.messages) {
    message->addFolder(this); // add this newly created folder to all messages
  }
}

void Folder::remove_from_Messages() {
  for (auto message : messages) {
    message->remFolder(this);
  }
  messages.clear();
}

Folder &Folder::operator=(const Folder &rhs) {
  if (this != &rhs) {
    remove_from_Messages();
    messages = rhs.messages;
    add_to_Messages(rhs);
  }
  return *this;
}

void Folder::print_debug() {
  for (auto e : messages)
    std::cout << e->contents << " ";
  std::cout << std::endl;
}

void swap(Message &lhs, Message &rhs) {
  using std::swap; // not strictly needed in this case, but good habit
  // remove pointers to each Message from their (original) respective Folders
  for (auto f : lhs.folders)
    f->remMsg(&lhs);
  for (auto f : rhs.folders)
    f->remMsg(&rhs);
  // swap the contents and Folder pointer sets
  swap(lhs.folders, rhs.folders);   // uses swap(set&, set&)
  swap(lhs.contents, rhs.contents); // swap(string&, string&)
  // add pointers to each Message to their (new) respective Folders
  for (auto f : lhs.folders)
    f->addMsg(&lhs);
  for (auto f : rhs.folders)
    f->addMsg(&rhs);
}

void swap(Folder &lhs, Folder &rhs) {
  using std::swap;
  for (auto m : lhs.messages)
    m->remFolder(&lhs);
  for (auto m : rhs.messages)
    m->remFolder(&rhs);

  swap(lhs.messages, rhs.messages);

  for (auto m : lhs.messages)
    m->addFolder(&lhs);
  for (auto m : rhs.messages)
    m->addFolder(&rhs);
}
