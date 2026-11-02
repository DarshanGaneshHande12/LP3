#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Node structure for Huffman Tree
struct Node
{
    char ch;
    int freq;

    Node* left;
    Node* right;

    Node(char c, int f)
    {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

// Compare frequencies (Min Heap)
struct Compare
{
    bool operator()(Node* a, Node* b)
    {
        return a->freq > b->freq;
    }
};

// Generate and print Huffman Codes
void printCodes(Node* root, string code)
{
    if (root == NULL)
        return;

    // Leaf node represents a character
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->ch << " : " << code << endl;
        return;
    }

    // Left edge = 0
    printCodes(root->left, code + "0");

    // Right edge = 1
    printCodes(root->right, code + "1");
}

// Build Huffman Tree
void huffman(vector<char>& chars, vector<int>& freq, int n)
{
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Insert all characters into Min Heap
    for (int i = 0; i < n; i++)
    {
        pq.push(new Node(chars[i], freq[i]));
    }

    // Build Huffman Tree
    while (pq.size() > 1)
    {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        // Create parent node with combined frequency
        Node* parent = new Node('$', left->freq + right->freq);

        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    cout << "\nHuffman Codes:\n";
    printCodes(pq.top(), "");
}

int main()
{
    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of characters!";
        return 0;
    }

    vector<char> chars(n);
    vector<int> freq(n);

    cout << "\nEnter characters:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> chars[i];
    }

    cout << "\nEnter frequencies:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> freq[i];

        if (freq[i] <= 0)
        {
            cout << "Frequency must be positive!";
            return 0;
        }
    }

    huffman(chars, freq, n);

    return 0;
}

/*
    HUFFMAN ENCODING:

    1. Huffman Encoding is a LOSSLESS data compression technique.
       It means the original data can be recovered without losing information.

    2. Usually, characters are stored using 8 bits (1 byte).
       Huffman Encoding assigns variable-length binary codes to characters.

    3. It aims to give:
       - Short binary codes to high-frequency characters.
       - Long binary codes to low-frequency characters.

    4. It uses a GREEDY approach.
       At every stage, it combines the two minimum-frequency nodes.
       Less-frequent characters generally end up deeper in the tree.

    5. Left edge = 0
       Right edge = 1

    SAMPLE INPUT:

    Number of characters: 6

    Characters:
    A B C D E F

    Frequencies:
    5 9 12 13 16 45

    SAMPLE OUTPUT (one possible result):

    F : 0
    C : 100
    D : 101
    A : 1100
    B : 1101
    E : 111

    TIME COMPLEXITY:

    1. Creating nodes and inserting into Min Heap: O(n log n)

    2. Building Huffman Tree: O(n log n)
       We perform (n-1) iterations.
       Each iteration extracts two nodes and inserts one parent.
       Each heap operation takes O(log n).

    3. Generating Huffman Codes: O(n)
       We visit each node of the Huffman Tree once.

    OVERALL TIME COMPLEXITY: O(n log n)

    AUXILIARY SPACE COMPLEXITY: O(n)
    The Min Heap and Huffman Tree require O(n) space.
*/
