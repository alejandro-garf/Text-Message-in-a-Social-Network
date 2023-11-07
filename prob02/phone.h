// Alejandro Fonseca
// CPSC 121L-06
// 11-6-23
// gfon@csu.fullerton.edu
// alejandro-garf
//
// Lab 9-1

#pragma once

#include <memory>
#include <string>
#include <vector>

#include "message.h"

class Phone {
 public:
  Phone(const std::string& owner);
  const std::string& GetOwner() const;
  std::shared_ptr<Message> AuthorMessage(const std::string& message);
  void AcceptMessage(std::shared_ptr<Message> message);
  void PrintMessages() const;

 private:
  std::string owner_;
  std::vector<std::shared_ptr<Message>> messages_;
};
