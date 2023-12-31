#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#define NUMBER_OF_IDEAS 10

class Brain {
private:
    std::string ideas[NUMBER_OF_IDEAS];

public:
    Brain();
    Brain(const Brain &);
    Brain& operator=(const Brain &);
    ~Brain();

    void                setIdeas(const std::string []);
    /* Returns a pointer TO AN ARRAY OF STRINGS"*/
    std::string*        getIdeas() const;
};


#endif // BRAIN_HPP