
// StrategyExo.cpp : Ce fichier contient la fonction 'main'. L'ex��cution du programme commence et se termine �� cet endroit.
//

#include <iostream>

class IFunFair
{
public:
    virtual std::string TypeManege() const = 0;
    virtual float getPrix() const = 0;
    ~IFunFair()
    {
        std::cout << "memoire desalouer\n";
    }

};


class Carousel : public IFunFair
{
public:
    std::string TypeManege() const override
    {
        return std::string("Carousel, vive les petits cheveux!!!!");
    }

    float getPrix() const override
    {
        return 18.0;
    }


};

class Autotemponesis : public IFunFair
{
public:
    std::string TypeManege() const override
    {
        return std::string("Auto tamponeuse, chouette on va pouvoir foncer sur des voitures!!!!");
    }

    float getPrix() const override
    {
        return 20.0;
    }

};

class PecheCanard : public IFunFair
{
public:
    std::string TypeManege() const override
    {
        return std::string("La peche au canard, Coin Coin Coin!!!");
    }

    float getPrix() const override
    {
        return 8.0;
    }
};

class EntreeAdulte
{
public:
    virtual ~EntreeAdulte()
    {
        delete attraction;
    }
    void Strategy(IFunFair* strategy)
    {
        attraction = strategy;
    }
    void Fun()
    {
        attraction->TypeManege();
        std::cout << "Vous allez au : " << attraction->TypeManege() << " pour " << attraction->getPrix() << " euros" << std::endl;

    }

protected:
    IFunFair* attraction;
};

class EntreeEnfant : public EntreeAdulte
{
public:
    void Fun()
    {
        std::cout << std::endl;
        std::cout << "A moitie prix pour les enfant " << std::endl;
        float prixreduit = attraction->getPrix() * 0.5;
        attraction->TypeManege();
        std::cout << "Vous allez au : " << attraction->TypeManege() << " pour " << prixreduit << " euros" << std::endl;

    }

};


int main()
{
    EntreeAdulte perso;
    perso.Strategy(new Carousel);
    perso.Fun();

    EntreeAdulte perso1;
    perso1.Strategy(new Autotemponesis);
    perso1.Fun();

    EntreeAdulte perso2;
    perso2.Strategy(new PecheCanard);
    perso2.Fun();

    EntreeEnfant enfant;
    enfant.Strategy(new Carousel);
    enfant.Fun();

    EntreeEnfant enfant1;
    enfant1.Strategy(new Autotemponesis);
    enfant1.Fun();

    EntreeEnfant enfant2;
    enfant2.Strategy(new PecheCanard);
    enfant2.Fun();

}
