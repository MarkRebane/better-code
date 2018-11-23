#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

void draw(const int& x, ostream& out, size_t position)
{
    out << string(position, ' ') << x << endl;
}

class object_t {
  public:
    object_t(const int& x) : self_(make_unique<int_model_t>(x))
    {
        cout << "ctor" << endl;
    }

    object_t(const object_t& x) : self_(make_unique<int_model_t>(*x.self_))
    {
        cout << "copy" << endl;
    }

    object_t(object_t&&) noexcept = default;

    object_t& operator=(const object_t& x) noexcept
    {
        return *this = object_t(x);
    }

    object_t& operator=(object_t&&) noexcept = default;

    friend void draw(const object_t& x, ostream& out, size_t position)
    {
        x.self_->draw_(out, position);
    }

  private:
    struct int_model_t {
        int_model_t(const int& x) : data_(x) {}

        void draw_(ostream& out, size_t position) const
        {
            draw(data_, out, position);
        }

        int data_;
    };

    unique_ptr<int_model_t> self_;
};

using document_t = vector<object_t>;

void draw(const document_t& x, ostream& out, size_t position)
{
    out << string(position, ' ') << "<document>" << endl;
    for (const auto& e : x) {
        draw(e, out, position + 2);
    }
    out << string(position, ' ') << "</document>" << endl;
}

object_t func()
{
    object_t result = 5;
    return result;
}

int main()
{
    // TODO Quiz 1: what does this print?
    // object_t x = func();

    // TODO Quiz 2: what does this print?
    // object_t x = 0;
    // x = func();

    document_t document;
    document.reserve(5);

    document.emplace_back(0);
    document.emplace_back(1);
    document.emplace_back(2);
    document.emplace_back(3);

    reverse(document.begin(), document.end());

    draw(document, cout, 0);
}
