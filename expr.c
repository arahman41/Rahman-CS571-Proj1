#include "expr.h"
#include "stdlib.h"
#include "stdio.h"


struct Expr *mk_plus(struct Expr *e1, struct Expr *e2) {
    struct Expr *ret = malloc(sizeof(struct Expr));
    ret->type = PLUS;
    ret->subexprs.e1 = e1;
    ret->subexprs.e2 = e2;

    return ret;
}

struct Expr *mk_minus(struct Expr *e1, struct Expr *e2) {
    struct Expr *ret = malloc(sizeof(struct Expr));
    ret->type = MINUS;
    ret->subexprs.e1 = e1;
    ret->subexprs.e2 = e2;

    return ret;
}

struct Expr *mk_times(struct Expr *e1, struct Expr *e2) {
    struct Expr *ret =  malloc(sizeof(struct Expr));
    ret->type = TIMES;
    ret->subexprs.e1 = e1;
    ret->subexprs.e2 = e2;

    return ret;
}

struct Expr *mk_div(struct Expr *e1, struct Expr *e2) {
    struct Expr *ret = malloc(sizeof(struct Expr));
    ret->type = DIV;
    ret->subexprs.e1 = e1;
    ret->subexprs.e2 = e2;

    return ret;
}

struct Expr *mk_float(float f) {
    struct Expr *ret = malloc(sizeof(struct Expr));
    ret->type = FLOAT;
    ret->literal = f;

    return ret;
}

/* This function should create the expr (1 + (4 * 5))
 * using the above constructors.
 */
struct Expr *mk_expr1() {
    /* TODO: Your code here */
    float x = 1;
    float y = 4;
    float z = 5;
    return mk_plus(mk_float(x),mk_times(mk_float(y),mk_float(z)));
}

/* This function should create the expr (1 + (7 / 8))
 * using the above constructors.
 */
struct Expr *mk_expr2() {
    /* TODO: Your code here */
    float x = 1;
    float y = 7;
    float z = 8;
    return mk_plus(mk_float(x),mk_div(mk_float(y),mk_float(z)));
}

/* This function should create the expr ((1 / 3) - (4 / (2 + 3)))
 * using the above constructors.
 */
struct Expr *mk_expr3() {
    /* TODO: Your code here */
    float a = 1;
    float b = 3;
    float c = 4;
    float d = 2;
    float e = 3;
    return mk_minus(mk_div(mk_float(a),mk_float(b)),mk_div(mk_float(c),mk_plus(mk_float(d),mk_float(e))));
}


/*
 * This function should free all memory associated 
 * with the given AST.
*/
void free_expr(struct Expr* e) {
    /* TODO: Your code here */
    free(e);    
}

/*
 * This function should evaluate the given AST and
 * return the floating-point result.
*/
float eval(struct Expr* e) {
    /* TODO: Your code here */

    if (e -> type == PLUS)
        {
            return eval(e->subexprs.e1) + eval(e->subexprs.e2);
        }
    else if (e -> type == MINUS)
    {
        return eval(e->subexprs.e1) - eval(e->subexprs.e2);
    }
    else if (e -> type == TIMES)
    {
        return eval(e ->subexprs.e1) * eval(e->subexprs.e2);
    }
    else if (e -> type == DIV)
    {
        return eval(e->subexprs.e1) / eval(e->subexprs.e2);
    }
    else if (e -> type == FLOAT)
    {
        return e->literal;
    }
    else{
        return 0.0;
    }
}




