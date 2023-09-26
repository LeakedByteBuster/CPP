#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm()
{
    #if defined(DEBUG)
        std::cout << "ShrubberyCreationForm default constructor is called\n";
    #endif // DEBUG

    std::cout << "You didn't give a file to ShrubberyCreationForm constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
    : AForm("ShrubberyCreationForm", 145, 137)
{
    #if defined(DEBUG)
        std::cout << "ShrubberyCreationForm parameterized constructor is called\n";
    #endif // DEBUG
    
    setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs) : AForm(rhs)
{
    #if defined(DEBUG)
        std::cout << "ShrubberyCreationForm copy constructor is called\n";
    #endif // DEBUG

    setTarget(rhs.getTarget());
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
    #if defined(DEBUG)
        std::cout << "ShrubberyCreationForm copy assignement operator is called\n";
    #endif // DEBUG

    if (this != &rhs){
        setIsSigned(rhs.getIsSigned());
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    #if defined(DEBUG)
        std::cout << "ShrubberyCreationForm destructor is called\n";
    #endif // DEBUG
}

#define ROOT_WIDTH 5 /* This MACRO determines how much big the tree will be */

void    ShrubberyCreationForm::childAction(std::string target) const
{
    /* Openning File */
    std::ofstream   ofs(target + "_shrubbery");
    if (!ofs)
    {
        ofs.close();
        std::cerr << "Cannot open the file " << target << std::endl;
        return ;
    }
    /* variables for drawing tree */
    const int   height = 50;
    const int   width = 100;
    const int   mid = 50;
    const int   heightLeaves = height / 1.1;
    bool        moreLeavesL = 0;

    /* Draw body part */
    ofs << std::endl;
    int x = ROOT_WIDTH;
    for (int i = 1; i < height; i++){   /* Iterate through lines */
        for (int j = 0; j < width; j++){ /* Iterate through width */
            if ((j == (mid - ROOT_WIDTH) || j == (mid + ROOT_WIDTH)))   /* Draw Root of the tree */
                ofs << "|";
            else if (((x <= heightLeaves) && j == (mid - x)) \
                || (moreLeavesL && (j < mid - ROOT_WIDTH)))  /* Draw left part */
                   {ofs << "/"; moreLeavesL = 1;}
            else if (((x <= heightLeaves) && j == (mid + x)))  /* Draw right part */
                ofs << "\\";
            else if ((j < mid + x) && (j > (mid + ROOT_WIDTH) && x <= heightLeaves))
                ofs << "\\"; /*  background for right part */
            #if !defined(TREE_BACKGROUND)
                else
                    ofs << " "; /* Puts white space */
            #else
                else if (j < mid - ROOT_WIDTH)
                    ofs << "\\"; /* Puts background for left part*/
                else if (j > mid + ROOT_WIDTH)
                    ofs << "/"; /* Puts background for right part*/
            #endif // TREE_BACKGROUND
        }
        x++;
        moreLeavesL = 0;
        ofs << std::endl;
    }
    ofs.close();
}