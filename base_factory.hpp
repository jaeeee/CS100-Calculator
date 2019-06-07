#ifndef __BASE_FACTORY_HPP__
#define __BASE_FACTORY_HPP__

#include <iostream>
#include "base.hpp"
#include <sstream>

using namespace std;

class BaseFactory {
    public:
        /* Constructor */
        BaseFactory() {}

        /* Pure Virtual Production Function */
        virtual Op* createOp(double value) = 0;
        virtual Rand* createRand() = 0;
};

#endif //__BASE_FACTORY_HPP__

class Double : public BaseFactory {
	public:
	    double value;
	    // double randValue = rand()%100;
	    stringstream ss;
      Double() {

      }

	    Double(double value) {
	       this->value = value;
	    }

	    Op* createOp(double val) {
	        return new Op(val);
	    }

	    Rand* createRand() {
	        return new Rand();
	    }
};


class Scientific : public BaseFactory {
	public:
	    int numPlaces;
	    // double randValue = rand()%100;

      Scientific() {

      }

	    Scientific(int a) {
        numPlaces = a;
      }

	    Op* createOp(double value) {
	    	 Op * temp = new SciOp(numPlaces, value);
	        return temp;
	    }

	    Rand* createRand() {
	        return new SciRand(numPlaces);
	    }
};

class Precision : public BaseFactory {
	public:

	    int numPlaces;

      Precision() {

      }

	    Precision(int a) {
        numPlaces = a;
      }

		Op* createOp(double value){
			// stringstream ss;
      //       ss << fixed << setprecision(numPlaces) << value;
      //       // cout << ss.st
      //       // cout << "BRO..." << endl;
      //       // cout << value << endl;
      //       return new Op(value);
      Op * temp = new PrecisionOp(numPlaces, value);
       return temp;
        }

        Rand* createRand() {
            return new PrecisionRand(3);
        }
};

// class Double : public BaseFactory {
// public:
//   //hey jason, i feel like the value storage is useless cause the create op passes through a value
//   //so i'm not sure if we should have both (double data) and createOp (double value). feels redundant
//   //double data;
//   Double() {
//     //data = val;
//   }
//
//   Op * createOp(double value) {
//     return new Op(value);
//   }
//
//   Rand * createRand() {
//     Rand * ptr = new Rand();
//     return ptr;
//   }
// };
//
// /**
// TODO
// **/
// class Scientific : public BaseFactory {
// public:
//   // double value;
//   Scientific() {
//     //value = a;
//   }
//   Op * createOp(double b) {
//     Op * temp = new SciOp(b);
//     return temp;
//   }
//   Rand * createRand() {
//     srand(time(0));
//     double RVal = rand() % 100;
//     Rand * temp = new SciRand(RVal);
//     return temp;
//   }
// };
//
// class Precision : public BaseFactory {
// public:
//     // double value;
//     int precision;
//
//     Precision(int a) {
//       precision = a;
//       // value = b;
//     }
//
//     Op * createOp(double a) {
//       Op * temp = new PrecisionOp(precision, a);
//       return temp;
//     }
//
//     Rand * createRand() {
//       //change if neccessary! not sure which val we should use (shouldn't matter right?)
//       srand(time(0));
//       double RVal = rand() % 100;
//       Rand * temp = new PrecisionRand(precision, RVal);
//       return temp;
//     }
// };
//
// class PrecisionRand : public BaseFactory {
//
// };
