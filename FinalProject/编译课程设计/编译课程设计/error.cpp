/*
** @author:止水清潇menghuanlater
** @date:2017-11-22
** @location:BUAA
*/
//跳读处理要注意读取下一个symbol的问题
#include <iostream>
#include "error.h"
using namespace std;

bool ErrorFlag = false;

void Error::LexicalAnalysisError(LexicalErrorCode errorCode,int lineNumber)const{
    ErrorFlag = true;
    switch(errorCode){
        case SingleCharIllegal:
            cout<<"At line: "<<lineNumber<<" exists single character illegal error."<<endl;
            break;
        case StringIllegal:
            cout<<"At line: "<<lineNumber<<" exists string illegal error."<<endl;
            break;
        case ContentIllegal:
            cout<<"At line: "<<lineNumber<<" exists contents illegal error."<<endl;
            break;
        case NotEqualSymIllegal:
            cout<<"At line: "<<lineNumber<<" exists symbol \'!=\' not match error."<<endl;
            break;
        default:break;
    }
}

void Error::SyntaxAnalysisError(SyntaxErrorCode errorCode,int lineNumber){
    ErrorFlag = true;
    switch(errorCode){
        case EmptyFileError:
            cout<<"Error(at line "<<lineNumber<<" [surround]): "<<"The file is empty!"<<endl;
            break;
        case AfterMainContentError:
            cout<<"Error(at line "<<lineNumber<<" [surround]): "<<"After structure:\"void main(){...}\" can\'t exist other contents!"<<endl;
            break;
        case NoMainFunctionError:
            cout<<"Error(at line "<<lineNumber<<" [surround]): "<<"Lack of void main function!"<<endl;
            break;
        case NotUnsignedIntegerError:
            cout<<"Error(at line "<<lineNumber<<" [surround]): "<<"array length must be more than 0."<<endl;
        case ZeroPrefixSignError:
            cout<<"Error(at line "<<lineNumber<<" [surround]): "<<"can\'t have + or - before 0."<<endl;
        default:break;
    }
}

void Error::SyntaxAnalysisError(SyntaxErrorCode errorCode,int lineNumber,string info){
    ErrorFlag = true;
    switch(errorCode){
        case LackComposedPartError:
            cout<<"Error(at line "<<lineNumber<<" [surround]): "<<info<<endl;
            break;
        default:break;
    }
}

void Error::SemanticAnalysisError(SemanticErrorCode errorCode, int lineNumber,string identifier) {
	ErrorFlag = true;
	switch (errorCode) {
		case DeclareConflictError:
			cout << "Error(at line " << lineNumber << " [surround]): identifier " << identifier << " have been defined." << endl;
			break;
		case NotDefinitionError:
			cout << "Error(at line " << lineNumber << " [surround]): identifier " << identifier << " not define before using." << endl;
			break;
		case FuncNotDefineError:
			cout << "Error(at line " << lineNumber << " [surround]): function " << identifier << " not define before using." << endl;
			break;
		case ArrIndexOutOfRangeError:
			cout << "Error(at line " << lineNumber << " [surround]): index out of array " << identifier << " range." << endl;
			break;
		case TypeNotMatchError:
			cout << "Error(at line " << lineNumber << " [surround]): identifier " << identifier << " not match it\'s real type." << endl;
			break;
		case StateIdNotMatchError:
			cout << "Error(at line " << lineNumber << " [surround]): identifier " << identifier << " not a function." << endl;
			break;
		case NeedValueButVoidFuncError:
			cout << "Error(at line " << lineNumber << " [surround]): identifier " << identifier << " function do not have return value." << endl;
			break;
		case NoneValueParamError:
			cout << "Error(at line " << lineNumber << " [surround]): identifier " << identifier << " value table is none illegal." << endl;
			break;
		case NoneParamButDeliverError:
			cout << "Error(at line " << lineNumber << " [surround]): identifier " << identifier << " function is none param, but deliver param to call it." << endl;
			break;
		case ParamNumNotMatchError:
			cout << "Error(at line " << lineNumber << " [surround]): identifier " << identifier << " deliver param number is not equal to function self param number ." << endl;
			break;
		case ParamTypeNotMatchError:
			cout << "Error(at line " << lineNumber << " [surround]): identifier " << identifier << " deliver param type is not match function self param type." << endl;
			break;
		case AssignIntToCharError:
			cout << "Error(at line " << lineNumber << " [surround]): can\'t assign int to char." << endl;
			break;
		case AssignObjectNotVar:
			cout << "Error(at line " << lineNumber << " [surround]): identifier " << identifier << " you assign to is not normal variable." << endl;
			break;
		case CaseSameValueError:
			cout << "Error(at line " << lineNumber << " [surround]): exist switch-case ,const value sets exist same value." << endl;
			break;
		case CaseTypeNotMatchError:
			cout << "Error(at line " << lineNumber << " [surround]): in switc-case statement case value type not match." << endl;
			break;
		default:break;
	}
}

void Error::ReturnStatementError(ReturnRelatedError errorCode, int lineNumber, string funcName) {
	ErrorFlag = true;
	switch (errorCode){
		case VoidButReturnValueError:
			cout << "Error(at line " << lineNumber << " [surround]): function " << funcName << " void function but return value." << endl;
			break;
		case CharButReturnIntError:
			cout << "Error(at line " << lineNumber << " [surround]): function " << funcName << " char function but return int." << endl;
			break;
		case ExistNoneReturnError:
			cout << "Error(at line " << lineNumber << " [surround]): function " << funcName << " have value return function not exist return value statement." << endl;
			break;
		case ExistReturnEmptyError:
			cout << "Error(at line " << lineNumber << " [surround]): function " << funcName << " have value return function exists empty return statement." << endl;
			break;
		default:break;
	}
}