# pragma once



#include <vector>
#include <string>
#include <memory>



namespace SERIALIZER {



class Serializer {
public:
    virtual ~Serializer() = default;

    virtual void add_field(const std::string& name, const std::string& value) = 0;

    virtual void add_block(const std::string& name) = 0;

    virtual void build() = 0;
};



class ChainOfBlocks : public Serializer {
public:
    struct Block {
        using name_field = std::string;
        using value_field = std::string;

        Block(const std::string& name) : name_block(name) {}

        std::string name_block{};
        std::vector<std::pair<name_field, value_field>> fields{};
    };

    void add_field(const std::string& name, const std::string& value) override;

    void add_block(const std::string& name) override;

protected:
    std::vector<Block> blocks{};
    std::vector<Block>::iterator current_block;
};



class XML_Serializer : public ChainOfBlocks {
public:
    void build() override;

private:
    void build_block(const Block& block, int indent);
};



class JSON_Serializer : public ChainOfBlocks {
public:
    void build() override;

private:
    void build_block(const Block& block, int indent);
};
};