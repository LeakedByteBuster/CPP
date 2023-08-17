#include <string>

std::string    giveMeName( void )
{
    static  int i = 0;

    if (i == 34)
        i = 0;
    std::string name[35] = {
        "Suckling", "Ripe", "Tender", "Driver", "Grazer", "Cackler", "Psycho", "Crusty",\
        "Digger", "Sneezer", "Lanky", "Runner", "Deducer", "Courier", "Spurter", "Jumper",  \
        "Taster", "Gaunt", "Scuttler", "Revoker", "Tickler", "Mutant", "Chewer", "Drizzler"    \
        "Wriggler", "Private", "Enhanced", "Sprouter", "Vomiter", "Rupture", "Puker", "Grower",\
        "Sloucher", "Gobbler", "Moaner", "Grazer"
    };
    i++;
    return (name[i]);
}
