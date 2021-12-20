#include <iostream>
#include <memory>

using namespace std;

int main() {
	shared_ptr<int> a = make_shared<int>(5);
	weak_ptr<int> wb = a;
	shared_ptr<int> b = wb.lock();
	cout << "a = " << *a << " b = " << *b << endl;
	*a = 4;
	cout << "a = " << *a << " b = " << *b << endl;
	return 0;
}