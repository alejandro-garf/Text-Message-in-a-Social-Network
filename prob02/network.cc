// Alejandro Fonseca
// CPSC 121L-06
// 11-6-23
// gfon@csu.fullerton.edu
// alejandro-garf
//
// Lab 9-1

// ========================= YOUR CODE HERE =========================
// This implementation file (network.cc) is where you should implement
// the member functions declared in the header (network.h), only
// if you didn't implement them inline within network.h.
//
// Remember to specify the name of the class with :: in this format:
//     <return type> MyClassName::MyFunction() {
//        ...
//     }
// to tell the compiler that each function belongs to the Network class.
// ===================================================================
#include "network.h"

#include <iostream>

#include "message.h"
#include "phone.h"

void Network::AddPhone(std::shared_ptr<Phone> phone) {
  phonebook_[phone->GetOwner()] = phone;
}

void Network::SendMessage(std::shared_ptr<Message> message,
                          const std::string& recipient) {
  if (phonebook_.count(recipient) != 0) {
    phonebook_[recipient]->AcceptMessage(message);
  }
}

void Network::SendMessage(std::shared_ptr<Message> message,
                          const std::vector<std::string>& recipients) {
  for (const std::string& recipient : recipients) {
    if (phonebook_.count(recipient) != 0) {
      phonebook_[recipient]->AcceptMessage(message);
    }
  }
}

void Network::PrintMessages(const std::string& owner) const {
  if (phonebook_.count(owner) != 0) {
    std::cout << "Printing messages sent to " << owner << ":" << std::endl;
    phonebook_.at(owner)->PrintMessages();
  }
}