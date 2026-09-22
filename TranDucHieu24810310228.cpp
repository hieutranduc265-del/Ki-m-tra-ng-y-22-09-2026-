#include <iostream>
#include <string>

using namespace std;


struct SinhVien {
    int maSV;
    string tenSV;
    string lop;
    float diemTongKet;
    string hanhKiem;
};

struct Node {
    SinhVien data;
    Node* left;
    Node* right;
};


void khoiTao(Node* &root) {
    root = NULL;
}


Node* taoNode(SinhVien sv) {
    Node* p = new Node;
    p->data = sv;
    p->left = NULL;
    p->right = NULL;
    return p;
}


Node* chenNode(Node* root, SinhVien sv) {
    if (root == NULL) {
        return taoNode(sv);
    }
    if (sv.maSV < root->data.maSV) {
        root->left = chenNode(root->left, sv);
    } else if (sv.maSV > root->data.maSV) {
        root->right = chenNode(root->right, sv);
    }
    return root;
}


Node* timKiem(Node* root, int maSV) {
    if (root == NULL || root->data.maSV == maSV) {
        return root;
    }
    if (maSV < root->data.maSV) {
        return timKiem(root->left, maSV);
    }
    return timKiem(root->right, maSV);
}


void duyietCay(Node* root) {
    if (root != NULL) {
        duyietCay(root->left);
        cout << "Ma SV: " << root->data.maSV << endl;
        cout << "Ten SV: " << root->data.tenSV << endl;
        cout << "Lop: " << root->data.lop << endl;
        cout << "Diem tong ket: " << root->data.diemTongKet << endl;
        cout << "Hanh kiem: " << root->data.hanhKiem << endl;
        cout << "----------------------" << endl;
        duyietCay(root->right);
    }
}


int main() {
    Node* root;
    khoiTao(root);

 Cau 3
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        SinhVien sv;
        cout << "Nhap sinh vien thu " << i + 1 << ":" << endl;
        cout << "Ma SV: ";
        cin >> sv.maSV;
        cin.ignore();
        cout << "Ten SV: ";
        getline(cin, sv.tenSV);
        cout << "Lop: ";
        getline(cin, sv.lop);
        cout << "Diem tong ket: ";
        cin >> sv.diemTongKet;
        cin.ignore();
        cout << "Hanh kiem: ";
        getline(cin, sv.hanhKiem);

        root = chenNode(root, sv);
    }

    // Cau 4
    cout << "\n=== DANH SACH SINH VIEN IN TU CAY ===" << endl;
    duyietCay(root);

    // Cau 5
    int maTim;
    cout << "Nhap ma sinh vien can tim: ";
    cin >> maTim;

    Node* result = timKiem(root, maTim);
    if (result != NULL) {
        cout << "\nTHONG TIN SINH VIEN TIM THAY:" << endl;
        cout << "Ma SV: " << result->data.maSV << endl;
        cout << "Ten SV: " << result->data.tenSV << endl;
        cout << "Lop: " << result->data.lop << endl;
        cout << "Diem tong ket: " << result->data.diemTongKet << endl;
        cout << "Hanh kiem: " << result->data.hanhKiem << endl;
    } else {
        cout << "Khong co sinh vien trong cay." << endl;
    }

    return 0;
}
