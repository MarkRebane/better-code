#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class object_t {
  public:
    virtual ~object_t() {}
    virtual void draw(ostream&, size_t) const = 0;
};

using document_t = vector<shared_ptr<object_t>>;

void draw(const document_t& x, ostream& out, size_t position)
{
    out << string(position, ' ') << "<document>" << endl;
    for (const auto& e : x) {
        e->draw(out, position + 2);
    }
    out << string(position, ' ') << "</document>" << endl;
}

class my_class_t final : public object_t {
  public:
    void draw(ostream& out, size_t position) const override
    {
        out << string(position, ' ') << "my_class_t" << endl;
    }
};

int main()
{
    document_t document;

    document.emplace_back(make_shared<my_class_t>());

    draw(document, cout, 0);
}
