#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

string ones[] = {"", "jeden", "dwa", "trzy", "cztery", "pięć", "sześć", "siedem", "osiem", "dziewięć"};
string tens[] = {"", "dziesięć", "dwadzieścia", "trzydzieści", "czterdzieści", "pięćdziesiąt", "sześćdziesiąt", "siedemdziesiąt", "osiemdziesiąt", "dziewięćdziesiąt"};
string teens[] = {"dziesięć", "jedenaście", "dwanaście", "trzynaście", "czternaście", "piętnaście", "szesnaście", "siedemnaście", "osiemnaście", "dziewiętnaście"};
string hundreds[] = {"", "sto", "dwieście", "trzysta", "czterysta", "pięćset", "sześćset", "siedemset", "osiemset", "dziewięćset"};

string convertToNumeral(int number)
{
	string numeral;
    int counter = 0, word;

    do
    {
        word = number % 10;
        number /= 10;

        if(counter == 0 && (number % 10) == 1)
            numeral = teens[word] + " " + numeral;

        if(counter == 0 && (number % 10) != 1)
            numeral = tens[number % 10] + " " + ones[word] + " " + numeral;

        if(counter == 2)
            numeral = hundreds[word] + " " + numeral;

        if(counter > 2)
        {
            if(counter == 3 && (number % 10) == 1)
                numeral = teens[word] + " tysięcy " + numeral;

            if(counter == 3 && (number % 10) != 1)
                if(word > 5 || (word == 1 && number % 10 != 0))
                    numeral = tens[number % 10] + " " + ones[word] + " tysięcy " + numeral;
                else if(word == 2 || word == 3 || word == 4)
                    numeral = tens[number % 10] + " " + ones[word] + " tysiące " + numeral;
                else if(word == 1)
                    numeral = "tysiąc " + numeral;

            if(counter == 5)
                numeral = hundreds[word] + " " + numeral;
        }

        counter++;
    }
	while(number > 0);

    return numeral;
}

int findK(int number)
{
    if(number == 0 || number == 1)
       return number;
 
    for(int k = 1; ; k++)
    {
        int result = number * k;
        while(result)
        {
            if(result % 10 != 0 && result % 10 != 1)
                break;
 
            result /= 10;
            if(result == 1)
                return k;
        }
    }
 }

int main(int argc, char *argv[])
{
	int number = atoi(argv[1]), k;

    k = findK(number);
	string numeralK = convertToNumeral(k), numeralNumberK = convertToNumeral(number*k);

    cout << "k: " << numeralK << endl << "n*k: " << numeralNumberK << endl;

}