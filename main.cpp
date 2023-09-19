#include <iostream>
#include <memory>

using namespace std;

void ejemplo_puntero_unico () {
    std::unique_ptr<int> ptr_u_1; // equivalente a nullptr
    // Reservar espacio
    ptr_u_1 = std::make_unique<int>(20);
    cout << *ptr_u_1 << endl;
    std::unique_ptr<int> ptr_u_2;
    ptr_u_2 = std::move(ptr_u_1);
    if (ptr_u_1 != nullptr)
         cout << *ptr_u_1 << endl;
    cout << *ptr_u_2 << endl;
    cout << boolalpha << static_cast<bool>(ptr_u_1) << endl;
    cout << boolalpha << static_cast<bool>(ptr_u_2) << endl;
    ptr_u_2 = nullptr;
}

void ejemplo_puntero_compartido () {
    std::shared_ptr<int> ptr_s_1;
    cout << ptr_s_1.use_count() << endl;
    ptr_s_1 = make_shared<int>(20);
    cout << ptr_s_1.use_count() << endl;
    std::shared_ptr<int> ptr_s_2;
    cout << ptr_s_2.use_count() << endl;
    ptr_s_2 = ptr_s_1;
    cout << ptr_s_1.use_count() << endl;
    cout << ptr_s_2.use_count() << endl;
//    cout << *ptr_s_1 << endl;
//    cout << *ptr_s_2 << endl;
}


int main() {
//    ejemplo_puntero_unico();
    ejemplo_puntero_compartido();
    return 0;
}
