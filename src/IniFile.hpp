#ifndef INIFILE_HPP_
#define INIFILE_HPP_

#include <map>
#include <istream>

namespace ini
{

    class IniField
    {
    private:
        std::string value_;
    public:
        IniField();
        IniField(const std::string &value);
        IniField(const IniField &field);
        ~IniField();

        const std::string &asString() const;
        int asInt() const;
        double asDouble() const;
        bool asBool() const;

        IniField &operator=(const IniField &field);
        IniField &operator=(const int value);
        IniField &operator=(const double value);
        IniField &operator=(const bool value);
        IniField &operator=(const std::string &value);
    };

    class IniSection: public std::map<std::string, IniField>
    {
    public:
        IniSection() { }
        ~IniSection() { }
    };

    class IniFile: public std::map<std::string, IniSection>
    {
    public:
        IniFile();
        IniFile(const std::string &fileName);
        IniFile(std::istream &is);
        ~IniFile();

        void decode(std::istream &is);
        void decode(const std::string &content);
        void encode(std::ostream &os);
        std::string encode();

        void load(const std::string &fileName);
        void save(const std::string &fileName);
    };
}

#endif
