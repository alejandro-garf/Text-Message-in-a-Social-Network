// Alejandro Fonseca
// CPSC 121L-06
// 11-6-23
// gfon@csu.fullerton.edu
// alejandro-garf
//
// Lab 9-1

#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "message.h"
#include "phone.h"

class Network {
 public:
  void AddPhone(std::shared_ptr<Phone> phone);
  void SendMessage(std::shared_ptr<Message> message,
                   const std::string& recipient);
  void SendMessage(std::shared_ptr<Message> message,
                   const std::vector<std::string>& recipients);
  void PrintMessages(const std::string& owner) const;

 private:
  std::map<std::string, std::shared_ptr<Phone>> phonebook_;
};
