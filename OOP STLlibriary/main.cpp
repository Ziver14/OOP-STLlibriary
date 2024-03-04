#include<iostream>

#include<array>//статический массив
#include<vector>//динамиский массив
#include<deque>//связнный список массивов с произвольным доступом


//коллекции языка с++
// требования ко вложенным типам и особенности работы
//


class DemoGood {
public:
	DemoGood() {
		std::cout << this << " create by defaul constructor\n";
	}
	DemoGood(int a, bool b) {
		std::cout << this << " create by parametric constructor\n";
	}
	DemoGood(const DemoGood& other) {
		std::cout << this << " create by copy constructor\n";
		std::cout << "from" << &other << " oblect\n";
	}
	~DemoGood() {
		std::cout << this << " destroed\n";
	}
};

class DemoBad {
public:
	DemoBad() = delete; //запретили компилятору использовать конструктор по умолчанию
	/*DemoBad(int a, bool b) {
		std::cout << this << " create by parametric constructor\n";
	}*/
	DemoBad(const DemoGood& other) {
		std::cout << this << " create by copy constructor\n";
		std::cout << "from" << &other << " oblect\n";
	}
	~DemoBad() {
		std::cout << this << " destroed\n";
	}
};



int main() {

	std::array<DemoGood, 10> arrST;
	// статический массив выделяет место под весь необходимый объем памяти
	//и заполняет его объектами созданными конструктором по умолчанию
	std::vector<DemoGood> arrDin;
	arrDin.reserve(10);
	//вектор не выделяет память если ему не сказаь,
	//но может отдельной командой зарезервировать место не создавая объекты
	std::deque<DemoGood> arrDeque(10);
	//деке как и вектору можно при создании сказать на какое колличество элементов она создана.
	//При этом будет необходимое колличество болванок с помощью конструктора по умолчанию


	/*std::array<DemoBad, 10> arrST2{
		DemoBad(1,true),
		DemoBad(2,true),
		DemoBad(3,true),
		DemoBad(4,true),
		DemoBad(5,true),
		DemoBad(6,true),
		DemoBad(7,true),
		DemoBad(8,true),
		DemoBad(9,true),
		DemoBad(0,true)
	};*/
	//в случае отсутствия конструктора по умолчанию для стандартных коллекций.
	//которым требуется сразу быть заполнеными какими то объектами, остается вариант
	// конструктора через список инициализации
	// именно такой список мы отправили{} 



	arrDin.push_back(DemoGood(0,true));
	arrDin.emplace_back(0, true);

	/*std::vector<DemoBad>nArr;
	nArr.push_back(DemoBad(0, true));
	nArr.emplace_back(0, true);*/
	//так как конструктор с параметрами недоступен методы категории emplace будут 
	//вызывать ошибки сборки с указанием на невозможность обращения к данному конструктору


	std::cout << "========================================================\n";
	std::vector<DemoGood> example;
	for (size_t i = 0; i < 17; i++)
	{
		example.emplace_back(i, bool(i % 2));
	}


	return 0;
}