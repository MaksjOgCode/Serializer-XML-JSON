#include "serializer.hpp"
#include <iostream>
#include <algorithm>



namespace S = SERIALIZER;



void print_xml() {
   std::cout << "\t\033[32mXML:\033[0m\n";
}



void print_json() {
   std::cout << "\033[36m\tJSON:\033[0m\n";
}



void S::ChainOfBlocks::add_field(const std::string& name, const std::string& value) {
   if ( this->blocks.empty() )
      throw std::runtime_error("No block to add field to [-1]:");

   this->blocks.back().fields.emplace_back(name, value);
}



void S::ChainOfBlocks::add_block(const std::string& name) {
   this->blocks.emplace_back(name);
}



void S::XML_Serializer::build() {
   if (! (this->blocks.empty()) )
   {
      print_xml();

      for (const auto& block : blocks)
         this->build_block(block, 0);
   }
}



void S::XML_Serializer::build_block(const Block& block, int indent) {
   std::string indent_str(indent, ' ');
   std::cout << indent_str << "<" << block.name_block << ">\n";

   for (const auto& field : block.fields)
      std::cout << indent_str << "  <" << field.first << ">" << field.second << "</" << field.first << ">\n";

   std::cout << indent_str << "</" << block.name_block << ">\n";
}



void S::JSON_Serializer::build() {
   if (! (this->blocks.empty()) )
   {
      print_json();
      std::cout << "{\n\n";

      for (const auto& block : blocks)
         this->build_block(block, 0);

      std::cout << "}\n";
   }
}



bool is_number(const std::string& str) {
   return std::all_of(str.begin(), str.end(), ::isdigit);
}



void S::JSON_Serializer::build_block(const Block& block, int indent) {
   indent += 2;
   std::string indent_str(indent, ' ');
   std::cout << indent_str << "\"" << block.name_block << "\": {\n";

   for (const auto& field : block.fields)
      std::cout << indent_str << "  \"" << field.first << "\": " << (is_number(field.second) ? field.second + "\n" : "\"" + field.second + "\",\n");

   std::cout << indent_str << "},\n\n";
}
