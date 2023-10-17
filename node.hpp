template <typename T>
class Node
{
public:
    T value_;
    Node *next_;

    Node(T value) : value_(value), next_(nullptr) {}
};