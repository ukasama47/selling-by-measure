
#include <iostream>
#include "assignment5.h"
#include <string>
using namespace std;

class apple : public base {//引き数は重さ　価格を返す

  private:
  double price;
  double weight;

  public: 
    apple (string nm, double up, double _weight) : base (nm, up){
    weight = _weight;
	}

  double get_price(double weight){
		price = 0;
		price = 1000 * weight;
		return price;
	}
};

class yogurt : public base {//引数は重さ　ヨーグルトの価格を返す

  private:
  double price;
  double weight;

  public: 
    yogurt (string nm, double up, double _weight) : base (nm, up){
    weight = _weight;
	}

	double get_price(double weight){
	  price = 0;
		price = 300 * weight + 50;
		return price;
	}	
};

int main(){//main関数内で入力を判別　関数を実行
		
  string name;
  double weight;	

  while (1){//ループする
    cout << "何を買いますか？(  apple  or  yogurt  )" << endl;//cinで入力を検知
	  cin >> name;
	  if ( name.compare( "apple" ) != 0 && name.compare ( "yogurt" ) != 0 ){
	    do {// when its wrong input
		    cout << "その商品はないかなぁ。打ち間違いをしていませんか？" << endl;
		    cout << "何を買いますか？ (  apple  or  yogurt  )" << endl;
	      cin >> name;	
	    }	while ( name.compare ( "apple" ) != 0 && name.compare ( "yogurt" ) != 0 );
	  }
	 
	cout << "何kg買いますか" << endl;//don't assume a large amount, its just a supermarket.
	cin >> weight;
	
	if ( name.compare ( "apple" ) == 0 ){
		apple a("リンゴ", 1000, weight);
		cout << a.get_name() << weight << "kg、お買い上げです。" << endl;
	  cout << a.get_price(weight) << "円になります。" << endl;
		}

	else if ( name.compare ( "yogurt" ) == 0 ){
		yogurt b("ヨーグルト", 300, weight);
		cout << b.get_name() << weight << "kg、お買い上げです。" << endl;
		cout << b.get_price(weight) << "円になります。" << endl;
		}
	cout << "次のお客様どうぞ" << endl;
	}
  return 0;	
}
