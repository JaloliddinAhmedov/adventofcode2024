#include <fstream>

#include <iostream>

using namespace std;

int son1 = 1, son2 = 1, sum = 0, docnt = 0, dontcnt = 0;
ifstream fin; // oqimnomi
char c;
bool bormi = false, holat1mi = false, dodo = true;
void gc() {
    bormi = fin >> c;
} // joriybelgi
int scan_g() {
    enum holat {
        BOSHQA,
        M,
        U,
        L,
        OCH_QAVS,
        YOP_QAVS,
        RAQAM,
        VERGUL,
        TUGASH,
        D,
        O,
        N,
        T,
        TUTUQ,
        DQAVSOCH,
        DQAVSYOP,
        DNQAVSOCH,
        DNQAVSYOP,
        ER
    }; //holatlar to'plami
    holat CS; // CS – joriy holat
    CS = BOSHQA;
    gc(); /* birinchi belgi o'qilmoqda */
    cout << "Boshlandi!\n";
    do switch (CS) {
    case BOSHQA:
        if (c == 'm' && dodo == true) {
            gc();
            CS = M;
            son1 = 0;
            son2 = 0;
        } else if (c == 'd') {
            CS = D;
            gc();
        } else if (!bormi) {
            CS = TUGASH;
        } else {
            gc();
            CS = BOSHQA;
            son1 = 0;
            son2 = 0;
        }
        break;

    case D:
        if (c == 'o') {
            gc();
            CS = O;
        } else if (!bormi) {
            CS = TUGASH;
        } else {
            gc();
            CS = BOSHQA;
        }
        break;
    case O:
        if (c == 'n') {
            gc();
            CS = N;
        } else if (c == '(') {
            gc();
            CS = DQAVSOCH;
        } else if (!bormi) {
            CS = TUGASH;
        } else {
            gc();
            CS = BOSHQA;
        }
        break;
    case N:
        if (c == '\'') {
            gc();
            CS = TUTUQ;
        } else if (!bormi) {
            CS = TUGASH;
        } else {
            gc();
            CS = BOSHQA;
        }
        break;
    case TUTUQ:
        if (c == 't') {
            gc();
            CS = T;
        } else if (!bormi) {
            CS = TUGASH;
        } else {
            gc();
            CS = BOSHQA;
        }
        break;
    case T:
        if (c == '(') {
            gc();
            CS = DNQAVSOCH;
        } else if (!bormi) {
            CS = TUGASH;
        } else {
            gc();
            CS = BOSHQA;
        }
        break;
    case DQAVSOCH:
        if (c == ')') {
            gc();
            CS = DQAVSYOP;
        } else if (!bormi) {
            CS = TUGASH;
        } else {
            gc();
            CS = BOSHQA;
        }
        break;
    case DQAVSYOP:
        docnt++;
        printf("\do(%c):domi=[%d]\n", c, dodo);
        dodo = true;
        if (c == 'd') {
            gc();
            CS = D;
            dodo = true;
        } else if (c == 'm') {
            gc();
            CS = M;
            dodo = true;
        } else if (!bormi) {
            CS = TUGASH;
        } else {
            gc();
            CS = BOSHQA;
            dodo = true;
        }
        break;

    case DNQAVSOCH:
        if (c == ')') {
            gc();
            CS = DNQAVSYOP;
        } else if (!bormi) {
            CS = TUGASH;
        } else {
            gc();
            CS = BOSHQA;
        }
        break;
    case DNQAVSYOP:
        dontcnt++;
        printf("\don''t(%c):domi=[%d\n", c, dodo);
        dodo = false;
        if (c == 'd') {
            gc();
            CS = D;
            dodo = false;
        } else if (!bormi) {
            CS = TUGASH;
        } else {
            gc();
            CS = BOSHQA;
            dodo = false;
        }
        break;

    case M:
        if (c == 'u') {
            gc();
            CS = U;
        } else if (!bormi) {
            CS = TUGASH;
        } else {
            gc();
            CS = BOSHQA;
        }
        break;
    case U:
        if (c == 'l') {
            gc();
            CS = L;
        } else if (!bormi) {
            CS = TUGASH;
        } else {
            gc();
            CS = BOSHQA;
        }
        break;
    case L:
        if (c == '(') {
            gc();
            CS = OCH_QAVS;
        } else if (!bormi) {
            CS = TUGASH;
        } else {
            gc();
            CS = BOSHQA;
        }
        break;
    case OCH_QAVS:
        if (c >= '0' && c <= '9') {
            CS = RAQAM;
            son1 = (c - '0');
            gc();
            holat1mi = true;
        } else if (!bormi) {
            CS = TUGASH;
        } else {
            gc();
            CS = BOSHQA;
        }
        break;
    case VERGUL:
        if ((c >= '0' && c <= '9')) {
            CS = RAQAM;
            son2 = (c - '0');
            gc();
            holat1mi = false;
        } else if (!bormi) {
            CS = TUGASH;
        } else {
            gc();
            CS = BOSHQA;
        }
        break;
    case RAQAM:
        if (c == ',') {
            gc();
            CS = VERGUL;
            holat1mi = false;
        } else if (c == ')' && holat1mi == false) {
            gc();
            CS = YOP_QAVS;
        } else if (c >= '0' && c <= '9') {
            if (holat1mi) {
                //				cout << "-1.1--\nson1 = "<<son1<<". c="<<c<<",amal="<<c-'0'<<"""\n";
                son1 = ((son1 * 10) + int(c - '0'));
                //				cout << "-1.2--\nson1 = "<<son1<<". c="<<c<<",amal="<<c-'0'<<"""\n";
            } else {
                son2 = (son2 * 10) + int(c - '0');
            }
            gc();
            CS = RAQAM;

        } else if (!bormi) {
            CS = TUGASH;
        } else {
            gc();
            CS = BOSHQA;
        }
        break;
    case YOP_QAVS:
        /*printf("\nmul(%d,%d)\n", son1,son2);*/ if (c == 'm') {
            gc();
            CS = M;
            sum += son1 * son2;
            son1 = 0;
            son2 = 0;
        } else if (!bormi) {
            CS = TUGASH;
            sum += son1 * son2;
        } else if (c == 'd') {
            gc();
            CS = D;
            sum += son1 * son2;
            son1 = 0;
            son2 = 0;
        } else {
            gc();
            CS = BOSHQA;
            sum += son1 * son2;
            son1 = 0;
            son2 = 0;
        }
        break;
    case TUGASH:
        break;

    default: {
        CS = BOSHQA;
        gc();
    }

    }
    while (CS != TUGASH && CS != ER);

    if (CS == ER) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    int i;
    fin.open("C:/Users/ahmj/Downloads/input_3_1.txt"); /* zanjir fayli ochiladi */
    i = scan_g();
    cout << "sum = " << sum << " cnt=" << dontcnt;

    return 0;
}
