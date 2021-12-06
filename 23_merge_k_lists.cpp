#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;

    ListNode()
        : val(0)
        , next(nullptr)
    {
    }
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }

    static ListNode* vector_to_ListNode(const vector<int>& sequence)
    {
        if (sequence.size() <= 0)
        {
            return nullptr;
        }

        ListNode* head{ new ListNode(sequence[0], nullptr) };
        ListNode* tail{ head };

        for (size_t i{ 1 }; i < sequence.size(); ++i)
        {
            tail->next = new ListNode(sequence[i], nullptr);
            tail = tail->next;
        }

        return head;
    }

    static void prn_ListNode_sequence(const ListNode* list_node)
    {
        if (list_node == nullptr)
        {
            return;
        }

        cout << list_node->val << (list_node->next == nullptr ? "\n" : " --> ");
        prn_ListNode_sequence(list_node->next);
    }

    static void del_ListNode(ListNode* list_node)
    {
        /* recursive version */
        if (list_node == nullptr)
        {
            return;
        }

        del_ListNode(list_node->next);
        delete list_node;

        // /* iteration version */
        // ListNode* cur;
        // while((cur = list_node) != nullptr)
        // {
        //     list_node = list_node->next;
        //     delete cur;
        // }
    }
};

class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (lists.size() == 0)
        {
            cout << "No list! Bye~~~" << endl;
            return nullptr;
        }
        else if (lists.size() == 1)
        {
            return lists[0];
        }

        vector<ListNode*> left_lists{ lists.begin(), lists.begin() + lists.size() / 2 };
        vector<ListNode*> right_lists{ lists.begin() + lists.size() / 2, lists.end() };

        ListNode* merged_left_lists{ mergeKLists(left_lists) };
        ListNode* merged_right_lists{ mergeKLists(right_lists) };

        ListNode* ptr_final_merged_list{ &final_merged_list };

        while (merged_left_lists and merged_right_lists)
        {
            if (merged_left_lists->val < merged_right_lists->val)
            {
                ptr_final_merged_list = ptr_final_merged_list->next = merged_left_lists;
                merged_left_lists = merged_left_lists->next;
            }
            else
            {
                ptr_final_merged_list = ptr_final_merged_list->next = merged_right_lists;
                merged_right_lists = merged_right_lists->next;
            }
        }

        ptr_final_merged_list->next = merged_left_lists ?  merged_left_lists : merged_right_lists;

        return final_merged_list.next;
    }

private:
    ListNode final_merged_list;
};

// [1,4,5],[1,3,4],[2,6]]
int main()
{
    ListNode* a[3];
    a[0] = ListNode::vector_to_ListNode({ 1, 4, 5 });
    a[1] = ListNode::vector_to_ListNode({ 1, 3, 4 });
    a[2] = ListNode::vector_to_ListNode({ 2, 6 });
    ListNode::prn_ListNode_sequence(a[0]);
    ListNode::prn_ListNode_sequence(a[1]);
    ListNode::prn_ListNode_sequence(a[2]);

    vector<ListNode*> lists{ a[0], a[1], a[2] };
    Solution s;

    ListNode* ret{ s.mergeKLists(lists) };

    cout << "result ==============================" << endl;
    ListNode::prn_ListNode_sequence(ret);

    ListNode::del_ListNode(ret);
}
