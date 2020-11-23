
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
char* strreplace(char* orig, char* rep, char* with);
char* repall(char* org);

int main(int argc, char* argv[]) {

    FILE* fPointer2;
    fPointer2 = fopen("Main.java", "w");
    
    char name[20];
    FILE* fPointer;
    fPointer = fopen(argv[1], "r");

    char singleLine[150];
    char end[9999] = "";

    while (!feof(fPointer)) {
        fgets(singleLine, 150, fPointer);
        strcat(end, singleLine);
    }
    char* res = repall(end);
    int size = strlen(res);
    res[size - 2] = '\0';
    fprintf(fPointer2, "%s", res);
    fclose(fPointer);
    system("start compile.exe");
	return 1;
}

char* repall(char* org) {
    char* _class = strreplace(org, "klass", "class");
    char* _interface = strreplace(_class, "schnittstelle", "interface");
    char* _abstract = strreplace(_interface, "abstrakt", "abstract");
    char* _extends = strreplace(_abstract, "erweitert", "extends");
    char* _implements = strreplace(_extends, "implementiert", "implements");
    char* _new = strreplace(_implements, "neu", "new");
    char* _this = strreplace(_new, "dies", "this");
    char* _super = strreplace(_this, "super", "super");

    char* _System = strreplace(_super, "System", "System");
    char* _out = strreplace(_System, "raus", "out");
    char* _println = strreplace(_out, "druckrh", "println");
    char* _print = strreplace(_println, "druck", "print");

    char* _public = strreplace(_print, "offentlichkeit", "public");
    char* _private = strreplace(_public, "privat", "private");
    char* _protected = strreplace(_private, "geschutzt", "protected");
    char* _static = strreplace(_protected, "statisch", "static");
    char* _main = strreplace(_static, "main", "main");
    char* _return = strreplace(_main, "ruckkehr", "return");
    char* _void = strreplace(_return, "leer", "void");
    char* _null = strreplace(_void, "null", "null");
    char* _args = strreplace(_null, "arge", "args");

    char* _int = strreplace(_args, "zahl", "int");
    char* _short = strreplace(_int, "kurz", "short");
    char* _byte = strreplace(_short, "byte", "byte");
    char* _long = strreplace(_byte, "lang", "long");
    char* _float = strreplace(_long, "schwebt", "float");
    char* _double = strreplace(_float, "dezimal", "double");
    char* _boolean = strreplace(_double, "boolsche", "boolean");
    char* _char = strreplace(_boolean, "char", "char");
    char* _String = strreplace(_char, "Zeichenfolge", "String");
    char* _length = strreplace(_String, ".longe", ".length");

    char* _for = strreplace(_length, "fur", "for");
    char* _while = strreplace(_for, "wahrend", "while");
    char* _continue = strreplace(_while, "fortsetz", "continue");
    char* _break = strreplace(_continue, "halt", "break");

    char* _if = strreplace(_break, "wenn", "if");
    char* _true = strreplace(_if, "wahr", "true");
    char* _false = strreplace(_true, "falsch", "false");

    return _false;
}


char* strreplace(char* orig, char* rep, char* with) {
    char* result; // the return string
    char* ins;    // the next insert point
    char* tmp;    // varies
    int len_rep;  // length of rep (the string to remove)
    int len_with; // length of with (the string to replace rep with)
    int len_front; // distance between rep and end of last rep
    int count;    // number of replacements

    // sanity checks and initialization
    if (!orig || !rep)
        return NULL;
    len_rep = strlen(rep);
    if (len_rep == 0)
        return NULL; // empty rep causes infinite loop during count
    if (!with)
        with = "";
    len_with = strlen(with);

    // count the number of replacements needed
    ins = orig;
    for (count = 0; tmp = strstr(ins, rep); ++count) {
        ins = tmp + len_rep;
    }

    tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);

    if (!result)
        return NULL;

    // first time through the loop, all the variable are set correctly
    // from here on,
    //    tmp points to the end of the result string
    //    ins points to the next occurrence of rep in orig
    //    orig points to the remainder of orig after "end of rep"
    while (count--) {
        ins = strstr(orig, rep);
        len_front = ins - orig;
        tmp = strncpy(tmp, orig, len_front) + len_front;
        tmp = strcpy(tmp, with) + len_with;
        orig += len_front + len_rep; // move to next "end of rep"
    }
    strcpy(tmp, orig);
    return result;
}