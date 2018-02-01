#include <iostream>
#include <memory>
#include <string>
#include <vector>

using std::shared_ptr;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::make_shared;
using std::string;

struct connection {
  string ip;
  int port;
  connection(string __ip, int __port) : ip(__ip), port(__port) {}
};

struct destination {
  string ip;
  int port;
  destination(string __ip, int __port) : ip(__ip), port(__port) {}
};

connection connect(destination *dest) {
  // real things: allocate resources for new connection connecting to dest
  cout << "connecting to destination: ip: " << dest->ip
       << " port: " << dest->port << endl;
  return connection(dest->ip, dest->port);
}

void disconnect(connection conn) {
  // real things: close connection, delete resources for this connection
  cout << "disconnect connection: ip: " << conn.ip << " port: " << conn.port
       << endl;
}

void end_connection(connection *ptr) { disconnect(*ptr); }

void do_things_with_dest(connection &conn) {
  shared_ptr<connection> resource_manager(&conn, end_connection);
  // do computation
  cout << "connection with dest complete" << endl;
}

int main() {
  destination dest("8.8.8.8", 6666);

  connection conn = connect(&dest);
  do_things_with_dest(conn);
}