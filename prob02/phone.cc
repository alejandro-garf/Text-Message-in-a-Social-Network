// Alejandro Fonseca
// CPSC 121L-06
// 11-6-23
// gfon@csu.fullerton.edu
// alejandro-garf
//
// Lab 9-1

// ========================= YOUR CODE HERE =========================
// This implementation file (phone.cc) is where you should implement
// the member functions declared in the header (phone.h), only
// if you didn't implement them inline within phone.h.
//
// Remember to specify the name of the class with :: in this format:
//     <return type> MyClassName::MyFunction() {
//        ...
//     }
// to tell the compiler that each function belongs to the Phone class.
// ===================================================================
#include "phone.h"

#include <iostream>

#include "message.h"

Phone::Phone(const std::string& owner) : owner_(owner) {}

const std::string& Phone::GetOwner() const { return owner_; }

std::shared_ptr<Message> Phone::AuthorMessage(const std::string& message) {
  return std::make_shared<Message>(message, owner_);
}

void Phone::AcceptMessage(std::shared_ptr<Message> message) {
  messages_.push_back(message);
}

void Phone::PrintMessages() const {
  for (const auto& message : messages_) {
    std::cout << message->GetSender() << ": " << message->GetMessage()
              << std::endl;
  }
}
