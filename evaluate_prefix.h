#ifndef EVALUATE_PREFIX_H
#define EVALUATE_PREFIX_H

#include <string>


/*  Klasa za izračunavanje aritmetičkog izraza danog u poljskoj notaciji.
 *  Binarne operacije su +,-,*,/ i ^.
 *  Unarne operacije ~ (negacija). Koristimo ~ umjesto - kako bismo
 *  mogli razlikovati unarnu od binarne operacije prema simbolu.
 *  Klasa radi samo s cjelobrojnim izrazima. 
 */
class Expression{
public:
    // tip izraza
    using Value = int;

    enum TokenType {operand, unaryOp, binaryOp};

    // pomoćna klasa koja predstavlja element izraza
    struct Token{
        TokenType type() const;
        char symbol() const;
        Value value() const;
    };

    // Konstrukcija izraza iz stringa.
    // text mora sadržavati aritmetički izraz u poljskoj notaciji
    Expression(std::string text);
    // Izračunaj vrijednost izraza. Može uništiti izraz, odnosno 
    // evaluate se ne može pozvati više puta.
    Value evaluate();
private:
    // Daje sljedeći token sadržan u izrazu 
    // (simbol operacije ili cijeli broj)
    Token getToken();
};

// NAPOMENA: Nije nužno koristiti unutarnju klasu  Expression::Token
//           ukoliko imate bolji način, no unutarnje klase su ovdje vrlo
//           prirodne.


#endif // EVALUATE_PREFIX_H
