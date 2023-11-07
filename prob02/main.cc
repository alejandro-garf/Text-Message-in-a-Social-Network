// Alejandro Fonseca
// CPSC 121L-06
// 11-6-23
// gfon@csu.fullerton.edu
// alejandro-garf
//
// Lab 9-2

#include <iostream>
#include <memory>
#include <vector>

#include "network.h"
#include "phone.h"

int main() {
  Network csuf_network;
  // Create 3 objects of type `std::shared_ptr<Phone>`.
  std::shared_ptr<Phone> phone1 = std::make_shared<Phone>("Anna");
  std::shared_ptr<Phone> phone2 = std::make_shared<Phone>("Raf");
  std::shared_ptr<Phone> phone3 = std::make_shared<Phone>("JC");

  // Add each phone to the Network, `csuf_network`.
  csuf_network.AddPhone(phone1);
  csuf_network.AddPhone(phone2);
  csuf_network.AddPhone(phone3);

  // Send the message "Sup" to Raf over the network, authored on Anna's phone.
  csuf_network.SendMessage(phone1->AuthorMessage("Sup"), "Raf");

  // Send the message "Lol" to Anna over the network, authored on Raf's phone.
  csuf_network.SendMessage(phone2->AuthorMessage("Lol"), "Anna");

  // Create a vector of strings containing "Anna" and "Raf" called `jcs_class`.
  std::vector<std::string> jcs_class = {"Anna", "Raf"};
  // Author a message on JC's phone and send the message "Hi class!" to everyone
  // in `jcs_class`.
  csuf_network.SendMessage(phone3->AuthorMessage("Hi class!"), jcs_class);

  // Send the message "Hi Prof!" to JC over the network, authored on Anna's
  // phone.
  csuf_network.SendMessage(phone1->AuthorMessage("Hi Prof!"), "JC");

  // Send the message "help how do C++" to JC over the network, authored on
  // Raf's phone.
  csuf_network.SendMessage(phone2->AuthorMessage("help how do C++"), "JC");

  // Display the messages on Anna's phone, Raf's phone, and JC's phone.
  std::cout << "Printing messages sent to Anna:" << std::endl;
  csuf_network.PrintMessages("Anna");

  std::cout << "Printing messages sent to Raf:" << std::endl;
  csuf_network.PrintMessages("Raf");

  std::cout << "Printing messages sent to JC:" << std::endl;
  csuf_network.PrintMessages("JC");
}
