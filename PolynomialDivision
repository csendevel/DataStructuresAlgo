#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class mnogozlen
{
	int degree;//степень
	double*koef;//массив коэффицентов
public:
	mnogozlen() {};//конструктор по умолчанию
	mnogozlen(const mnogozlen& pol);//Конструктор копирования
	mnogozlen(int count);//Конструктор преобразования типа
	~mnogozlen() { delete[] koef; }//Деструктор
	mnogozlen operator+(mnogozlen&);//Сумма
	mnogozlen operator-(mnogozlen&);//Разность
	mnogozlen& operator=(mnogozlen&);//присваивание
	mnogozlen operator*(mnogozlen&);//Умножение полинома на полином
	mnogozlen operator/(mnogozlen&);//Целая часть от деления
	mnogozlen operator%(mnogozlen&);//Остаток от деления
	int GetDegr() { return degree; }//Получение степени
	double calcul(int); //Расчет значения
	int push(double, double*);//Ввод полинома
	friend ostream &operator<<(ostream &, mnogozlen &);// Перегрузка оператора << для вывода в поток
};

mnogozlen::mnogozlen(int count)
{
	degree = count;
	koef = new double[degree + 1];
}
mnogozlen::mnogozlen(const mnogozlen& ob)
{
	degree = ob.degree;
	koef = new double[degree + 1];
	for (int i = degree;i >= 0;i--)
		koef[i] = ob.koef[i];
}
int mnogozlen::push(double n, double *k)
{
	degree = n;
	koef = new double[degree + 1];
	for (int i = n; i >= 0; i--)
		koef[i] = k[i];
	return 0;
}

ostream &operator<<(ostream &fo, mnogozlen &o)
{
	int f = 0;

	for (int i = o.degree;i >= 0;i--)
		if (o.koef[i] != 0) {
			if (f == 0) {
				if (i != 0) fo << o.koef[i] << "*x^" << i;
				else fo << o.koef[i]; f++;
			}
			else {
				if (i != 0)
					if (o.koef[i] > 0) fo << "+" << o.koef[i] << "*x^" << i;
					else fo << o.koef[i] << "*x^" << i;
				else  if (o.koef[i] > 0) fo << "+" << o.koef[i];
				else fo << o.koef[i]; f++;
			}
		}
	if (f == 0) { fo << 0; }

	fo << endl;

	return fo;
}


mnogozlen mnogozlen::operator+(mnogozlen& ob)
{
	if (degree == ob.degree)
	{
		mnogozlen temp(degree);
		for (int i = ob.degree;i >= 0;i--)
			temp.koef[i] = koef[i] + ob.koef[i];
		return temp;
	}
	if (degree < ob.degree)
	{
		mnogozlen temp(ob.degree);
		for (int i = degree;i >= 0;i--)
			temp.koef[i] = koef[i] + ob.koef[i];
		for (int i = ob.degree;i >= degree + 1;i--)
			temp.koef[i] = ob.koef[i];
		return temp;
	}
	if (degree > ob.degree)
	{
		mnogozlen temp(degree);
		for (int i = ob.degree;i >= 0;i--)
			temp.koef[i] = koef[i] + ob.koef[i];
		for (int i = degree;i >= ob.degree + 1;i--)
			temp.koef[i] = koef[i];
		return temp;
	}
	return *this;
}
mnogozlen mnogozlen::operator-(mnogozlen& ob)
{
	if (degree == ob.degree)
	{
		mnogozlen temp(degree);
		for (int i = ob.degree;i >= 0;i--)
			temp.koef[i] = koef[i] - ob.koef[i];
		return temp;
	}
	if (degree < ob.degree)
	{
		mnogozlen temp(ob.degree);
		for (int i = degree;i >= 0;i--)
			temp.koef[i] = koef[i] - ob.koef[i];
		for (int i = ob.degree;i >= degree + 1;i--)
			temp.koef[i] = ob.koef[i];
		return temp;
	}
	if (degree > ob.degree)
	{
		mnogozlen temp(degree);
		for (int i = ob.degree;i >= 0;i--)
			temp.koef[i] = koef[i] - ob.koef[i];
		for (int i = degree;i >= ob.degree + 1;i--)
			temp.koef[i] = koef[i];
		return temp;
	}
	return *this;
}
mnogozlen mnogozlen::operator *(mnogozlen& ob)
{
	mnogozlen temp;
	temp.degree = degree + ob.degree;
	temp.koef = new double[temp.degree + 1];
	memset(temp.koef, 0, (temp.degree + 1) * sizeof(double));
	for (int i = 0;i <= degree;i++)
	{
		for (int j = 0;j <= ob.degree;j++)
		{
			temp.koef[i + j] += koef[i] * ob.koef[j];
		}
	}
	return temp;
}
mnogozlen mnogozlen::operator /(mnogozlen& ob)
{
	mnogozlen temp;
	mnogozlen ob_1;
	mnogozlen ob_2;
	mnogozlen ob_4;

	temp.degree = degree - ob.degree;
	temp.koef = new double[temp.degree + 1];
	memset(temp.koef, 0, (temp.degree + 1) * sizeof(double));

	ob_1.degree = degree;
	ob_1.koef = new double[degree + 1];
	for (int i = degree;i >= 0;i--)
		ob_1.koef[i] = koef[i];


	ob_2.degree = ob.degree;
	ob_2.koef = new double[ob.degree + 1];
	for (int i = ob.degree;i >= 0;i--)
		ob_2.koef[i] = ob.koef[i];

	ob_4.degree = ob.degree;
	ob_4.koef = new double[ob_1.degree + 1];

	int u = 0;
	int j = 0;
	int k = ob_1.degree;
	while (u == 0)
	{
		if (ob_1.degree >= ob_2.degree)
		{
			j = ob_2.degree;
			for (int i = ob_1.degree; i >= 0; i--)
			{
				if (j >= 0)
				{
					ob_4.koef[i] = ob_2.koef[j];
					j--;
				}
				else ob_4.koef[i] = 0;
			}


			for (int i = 0; i <= ob_1.degree; i++)
				ob_4.koef[i] *= ob_1.koef[k];

			temp.koef[ob_1.degree - 1] = ob_1.koef[k];

			for (int i = 0; i <= ob_1.degree; i++)
				ob_1.koef[i] -= ob_4.koef[i];

		}
		else u = 1;
		k--;
		ob_1.degree--;
	}
	return temp;
}

mnogozlen mnogozlen::operator %(mnogozlen &ob)
{

	bool inAlgoritm = true;

	mnogozlen ob_1;
	mnogozlen ob_2;
	mnogozlen ob_4;

	ob_1.degree = degree;
	ob_1.koef = new double[degree + 1];
	for (int i = degree; i >= 0; i--)
		ob_1.koef[i] = koef[i];

	ob_2.degree = ob.degree;
	ob_2.koef = new double[ob.degree + 1];
	for (int i = ob.degree; i >= 0; i--)
		ob_2.koef[i] = ob.koef[i];

	ob_4.degree = ob_1.degree;
	ob_4.koef = new double[ob_1.degree + 1];

	double mnojnik;
	int i, j;
	while (inAlgoritm)
	{

		for (int i = ob.degree; i >= 0; i--)
			ob_4.koef[i] = ob.koef[i];

		if (ob_2.degree < ob_1.degree)
		{
			for (i = ob_1.degree, j = ob_2.degree; i >= 0; i--, j--)
				if (j < 0)
					ob_4.koef[i] = 0;
				else
					ob_4.koef[i] = ob_2.koef[j];
		}



		mnojnik = ob_1.koef[ob_1.degree] / ob_4.koef[ob_1.degree];


		for (int i = 0; i <= ob_1.degree; i++)
			ob_4.koef[i] *= mnojnik;

		for (int i = 0; i <= ob_1.degree; i++)
			ob_1.koef[i] -= ob_4.koef[i];

		ob_1.degree--;
		if (ob_2.degree > ob_1.degree) inAlgoritm = false;

	}

	return ob_1;

}

mnogozlen& mnogozlen::operator =(mnogozlen& t)
{
	if (this == &t)
	{
		return *this;
	}
	degree = t.degree;
	for (int i = degree;i >= 0;i--)
		koef[i] = t.koef[i];
	return *this;
}

double mnogozlen::calcul(int n)
{
	int g = 1, j = 1;
	double p = 0;
	for (int i = 0; i <= degree; i++)
	{
		while (j == i) { j++; g *= n; }
		p += koef[i] * g;
	}
	return p;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 0;
	int k = 0;
	int u = 0;
	double *koef, *koef1;

	cout << "Введите степень первого многочлена\n";
	cin >> n;

	mnogozlen p(n);
	koef = new double[n + 1];
	for (int i = 0;i <= n;i++)
	{
		cout << "Koef[" << i << "] ";
		cin >> koef[i];
	}
	p.push(n, koef);

	int m = 0;
	cout << "Введите степень второго многочлена\n";
	cin >> m;

	mnogozlen s(m);
	koef1 = new double[m + 1];
	for (int i = 0;i <= m;i++)
	{
		cout << "Koef[" << i << "] ";
		cin >> koef1[i];
	}
	s.push(m, koef1);

	cout << "Первый многочлен: " << p << '\n';
	cout << "Второй многочлен: " << s << '\n';

	if (p.GetDegr() >= s.GetDegr())
		k = p.GetDegr();
	else
		k = s.GetDegr();

	cout << "Деление многочленов:" << '\n';
	mnogozlen y(p.GetDegr() - s.GetDegr());
	y = p / s;
	cout << "Частное от деления = " << y << '\n';


	cout << "Введите значение x = ";
	cin >> u;
	cout << endl;
	cout << "Первый многочлен = " << p.calcul(u) << endl;
	cout << "Второй многочлен = " << s.calcul(u) << endl;

	return 0;
}
