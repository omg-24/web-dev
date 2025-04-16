int main() {
    Node* root = nullptr;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Min value: " << findMin(root)->data << endl;
    cout << "Max value: " << findMax(root)->data << endl;

    cout << "Search 40: " << (search(root, 40) ? "Found" : "Not Found") << endl;
    cout << "Search 90: " << (search(root, 90) ? "Found" : "Not Found") << endl;

    root = deleteNode(root, 70);
    cout << "After deleting 70: ";
    inorder(root);
    cout << endl;

    return 0;
}
int main() {
    Node* root = nullptr;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Min value: " << findMin(root)->data << endl;
    cout << "Max value: " << findMax(root)->data << endl;

    cout << "Search 40: " << (search(root, 40) ? "Found" : "Not Found") << endl;
    cout << "Search 90: " << (search(root, 90) ? "Found" : "Not Found") << endl;

    root = deleteNode(root, 70);
    cout << "After deleting 70: ";
    inorder(root);
    cout << endl;

    return 0;
}
