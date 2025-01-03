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
   if (this->current_block != nullptr)
      this->current_block->fields.emplace_back(name, value);
}



void S::ChainOfBlocks::add_block(const std::string& name) {
   if (this->root_block == nullptr)
   {
      this->current_block = new Block (name);
      this->root_block = std::unique_ptr <Block> (this->current_block);
   }
   else
   {
      auto new_block = std::make_unique <Block> (name);
      this->current_block = new_block.get();
      this->root_block->sub_blocks.push_back( std::move(new_block) );
   }
}



void S::XML_Serializer::build() {
   if (this->root_block != nullptr)
   {
      print_xml();
      this->build_block( *root_block, 0);
   }
}



void S::XML_Serializer::build_block(const Block& block, int indent) {
   std::string indent_str(indent, ' ');
   std::cout << indent_str << "<" << block.name_block << ">\n";

   if ( &block == root_block.get() )
      std::cout << "\n";

   for (const auto& field : block.fields)
      std::cout << indent_str << "  <" << field.first << ">" << field.second << "</" << field.first << ">\n";

   for (const auto& sub_block : block.sub_blocks)
   {
      build_block(*sub_block, indent + 2);
      std::cout << "\n";
   }

   std::cout << indent_str << "</" << block.name_block << ">\n";
}



void S::JSON_Serializer::build() {
   if (this->root_block != nullptr)
   {
      print_json();

      std::cout << "{\n\n";

      this->build_block(*root_block, 0);
      std::cout << "  }\n";

      std::cout << "\n}\n";
   }
}



bool is_number(const std::string& str) {
   return std::all_of(str.begin(), str.end(), ::isdigit);
}



void S::JSON_Serializer::build_block(const Block& block, int indent) {
   indent += 2;
   std::string indent_str(indent, ' ');
   std::cout << indent_str << "\"" << block.name_block << "\": {\n";

   if ( &block == root_block.get() )
      std::cout << "\n";

   for (const auto& field : block.fields)
      std::cout << indent_str << "  \"" << field.first << "\": " << (is_number(field.second) ? field.second + "\n": "\"" + field.second + "\",\n");

   if ( &block != root_block.get() )
      std::cout << indent_str << "},\n\n";

   for (const auto& sub_block : block.sub_blocks)
      build_block(*sub_block, indent + 2);
}