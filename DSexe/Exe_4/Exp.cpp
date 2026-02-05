#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    Node(T VAL) : val(VAL)
    {
    }
    T val;
    Node<T> *next = nullptr;
};

template <class T>
class List
{
    Node<T> *head_ = nullptr;

public:
    List()
    {
        head_ = new Node<T>(int(0));
    }
    ~List()
    {
        while (head_ != nullptr)
        {
            Node<T> *temp = head_;

            head_ = head_->next;
            if (temp != nullptr)
            {
                delete temp;
            }
        }
    }
    void push_back(T VAL)
    {
        Node<T> *cur = head_;
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        Node<T> *now = new Node<T>(VAL);
        cur->next = now;
    }
    Node<T> *get_head()
    {
        return head_;
    }
};
template <typename T>
Node<T> *in_circle(Node<T> *Head)
{
    Node<T> *ptr_fast = Head;
    Node<T> *ptr_slow = Head;

    if (ptr_fast->next != nullptr)
    {
        ptr_slow = ptr_slow->next;

        ptr_fast = ptr_fast->next->next;
    }
    else
    {
        return nullptr;
    }
    while (ptr_fast != ptr_slow && ptr_fast != nullptr)
    {
        if (ptr_fast->next == nullptr)
        {
            return nullptr;
        }
        ptr_slow = ptr_slow->next;

        ptr_fast = ptr_fast->next->next;
    }
    if (ptr_fast == nullptr)
    {
        return nullptr;
    }
    ptr_slow = Head;
    while (ptr_fast != ptr_slow)
    {
        ptr_slow = ptr_slow->next;

        ptr_fast = ptr_fast->next;
    }
    return ptr_fast;
}

int main()
{
    cout << "--- 链表环路检测测试 ---" << endl;

    // ----------------------------------------------------
    // 测试 1: 线性链表 (无环)
    // ----------------------------------------------------
    cout << "\n--- 测试 1: 创建一个无环链表 (10 -> 20 -> 30) ---" << endl;
    List<int> linearList;
    linearList.push_back(10);
    linearList.push_back(20);
    linearList.push_back(30);

    Node<int> *entry1 = in_circle(linearList.get_head());

    if (entry1 == nullptr)
    {
        cout << "结果: 正确 (Test Passed)" << endl;
        cout << "  -> 未找到环路 (返回 nullptr)" << endl;
    }
    else
    {
        cout << "结果: 错误 (Test Failed)" << endl;
        cout << "  -> 错误地在 " << entry1->val << " 处找到了环路" << endl;
    }
    // linearList 在这里超出作用域, 它的析构函数会被安全调用

    // ----------------------------------------------------
    // 测试 2: 带环链表
    // 结构: Head -> 1 -> 2 -> 3 -> 4 -> 5
    //                       ^         |
    //                       |_________| (5 指向 3)
    // ----------------------------------------------------
    cout << "\n--- 测试 2: 创建一个有环链表 (5 指向 3) ---" << endl;

    List<int> circularList;
    circularList.push_back(1);
    circularList.push_back(2);
    circularList.push_back(3); // 环的入口
    circularList.push_back(4);
    circularList.push_back(5); // 环的尾部

    // 手动创建环路
    Node<int> *head = circularList.get_head();
    // 找到节点 3 (Head -> 1 -> 2 -> 3)
    Node<int> *loopEntryNode = head->next->next->next;
    // 找到节点 5 (Head -> 1 -> 2 -> 3 -> 4 -> 5)
    Node<int> *tailNode = loopEntryNode->next->next;

    cout << "创建环路: 从节点 " << tailNode->val << " 指向节点 " << loopEntryNode->val << endl;
    tailNode->next = loopEntryNode; // 制造环： 5 -> 3

    Node<int> *entry2 = in_circle(circularList.get_head());

    if (entry2 == loopEntryNode)
    {
        cout << "结果: 正确 (Test Passed)" << endl;
        cout << "  -> 环路入口在 " << entry2->val << " (符合预期)" << endl;
    }
    else if (entry2 == nullptr)
    {
        cout << "结果: 错误 (Test Failed)" << endl;
        cout << "  -> 未找到环路 (返回 nullptr)" << endl;
    }
    else
    {
        cout << "结果: 错误 (Test Failed)" << endl;
        cout << "  -> 环路入口在 " << entry2->val << " (预期为 " << loopEntryNode->val << ")" << endl;
    }

    // ----------------------------------------------------
    // 关键步骤：清理
    // ----------------------------------------------------
    cout << "\n--- 测试结束，清理环路 ---" << endl;
    // 在 main 结束前，必须手动断开环路
    // 否则 ~List() 析构函数会陷入无限循环！
    tailNode->next = nullptr;
    cout << "环路已断开, 准备安全退出。" << endl;

    return 0;
    // circularList 在这里超出作用域, 它的析构函数现在可以安全调用了
}