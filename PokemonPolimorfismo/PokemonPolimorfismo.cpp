// PokemonPolimorfismo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include<windows.h>  

int potions{ 3 };
int pokemonsAlive{ 4 };

class Pokemon
{
public:
    //Constructor generico
    Pokemon()
    {
        this->name = "Eevee";
        this->type = "Normal";
        this->color = "Brown";
        this->attack = 30.f;
        this->health = 120;
    }
    //Constructor Especifico
    Pokemon(std::string name, std::string type, std::string color, float attack, float health)
    {
        this->name = name;
        this->type = type;
        this->color = color;
        this->attack = attack;
        this->health = health;
    }
protected:
    //Atributos
    std::string name = "";
    std::string type = "";
    std::string color = "";
    std::string weakness = "";
    bool alive = true;
    float attack{ 0.f };
    float health{ 0.f };
public:
    //Getters
    std::string GetName()
    {
        return this->name;
    }
    std::string GetType()
    {
        return this->type;
    }
    std::string GetColor()
    {
        return this->color;
    }
    std::string GetWeakness()
    {
        return this->weakness;
    }
    float GetHealth()
    {
        return this->health;
    }
    float GetAttack()
    {
        return this->attack;
    }
    bool GetIsAlive()
    {
        return this->alive;
    }
    //setters
    void SetName(std::string name)
    {
        this->name = name;
    }
    void SetWeakness(std::string weakness)
    {
        this->weakness = weakness;
    }
    void SetType(std::string type)
    {
        this->type = type;
    }
    void SetColor(std::string color)
    {
        this->color = color;
    }
    void SetAttack(float attack)
    {
        this->attack = attack;
    }
    void SetHealth(float health)
    {
        this->health = health;
    }
    //Metodos
    void ShowStats()
    {
        std::cout << "Pokemon Name: " << this->name << std::endl <<
            "Type: " << this->type << std::endl <<
            "Color: " << this->color << std::endl <<
            "Health: " << this->health << std::endl <<
            "Attack: " << this->attack << std::endl;
    }
    void Evolve(std::string newName, std::string newColor, bool changeType = false, std::string typeToChange = "")
    {
        this->name = newName;
        this->color = newColor;
        this->attack = this->attack * 1.3f;

        if (!changeType) return;

        this->type = typeToChange;
    }
    void Heal(float healPoints = 50.f)
    {
        std::cout << "Your " << this->name << " went from " << this->health << " health points to: "
            << this->health + healPoints << " health points" << std::endl;

        this->health += healPoints;
    }

    virtual void Attack(Pokemon* oponent) { 
        oponent->GetHitted(attack);
    }
    void GetHitted(float damage) {
        if (this->health > damage) {
            this->health -= damage;

            std::cout << this->name << " lost " << damage << " ps; Current health: " << this->health;
            Sleep(1444);
            system("CLS");
        }
        else
        {
            this->health = 0;
            this->alive = false;
        }
    }

    //Destructor
    ~Pokemon()
    {
        //std::cout << "The Pokemon " << name << " of type " << type << " has been deleted" << std::endl;
    }
};

class Fire : public Pokemon {
public:
    //Contructores
    Fire() : Pokemon() {
        this->name = "Charmander";
        this->type = "Fire";
        this->weakness = "Water";
        this->color = "Orange";
        this->attack = 45.f;
        this->health = 110;
        this->fuel = 100;
        this->temperature = 234;
    }

    Fire(std::string name, std::string color, float attack, float health, int temperature, int fuel, std::string type = "") : Pokemon(name, type, color, attack, health) {

        this->type = "Fire";
        this->weakness = "Water";
        this->name = name;
        this->color = color;
        this->attack = attack;
        this->health = health;
        this->temperature = temperature;
        this->fuel = fuel;
    }
private:
    //Propiedades
    int temperature{ 0 };
    int fuel{ 0 };

public:
    //Getters
    int GetTemperature() {
        return this->temperature;
    }
    int GetFuel() {
        return this->fuel;
    }
    //Setters
    void SetTemperature(int temperature) {
        this->temperature = temperature;
    }
    void SetFuel(int fuel) {
        this->fuel = fuel;
    }
    //Metodos
    void HeatTheSoup() {
        std::cout << name << " heated the soup" << std::endl;
        temperature += 5;
        fuel -= 5;
    }
    void ShowStats() {
        Pokemon::ShowStats();
        std::cout << "Temperature: " << temperature << std::endl <<
            "Fuel: " << fuel << std::endl;
    }
    void Attack(Pokemon* oponent) override {
        std::cout << this->name << " use Blaze Kick" << std::endl;

        if (oponent->GetWeakness() == this->type)
        {
            oponent->GetHitted(attack * 2);
            std::cout << "Its very efective" << std::endl;
            Sleep(1444);
            system("CLS");
        }

        else oponent->GetHitted(attack);
    }
};

class Water : public Pokemon {
public:
    //Constructores
    Water() : Pokemon() {
        this->name = "Squirtle";
        this->type = "Water";
        this->weakness = "Plant";
        this->color = "Blue";
        this->attack = 35.f;
        this->health = 100.f;
        this->oxygen = 100;
        this->swimSpeed = 50;
    }
    Water(std::string name, std::string color, float attack, float health, int oxygen, int swimSpeed, std::string type = "") : Pokemon(name, type, color, attack, health) {
        this->type = "Water";
        this->weakness = "Plant";
        this->name = name;
        this->color = color;
        this->attack = attack;
        this->health = health;
        this->oxygen = oxygen;
        this->swimSpeed = swimSpeed;
    }
private:
    //Propiedades
    int oxygen = 0;
    int swimSpeed = 0;
public:
    //Getters
    int GetOxygen() {
        return this->oxygen;
    }
    int GetSwimSpeed() {
        return this->swimSpeed;
    }
    //Setters
    void SetOxygen(int oxygen) {
        this->oxygen = oxygen;
    }
    void SetSwimSpeed(int swimSpeed) {
        this->swimSpeed = swimSpeed;
    }
    //Metodos
    void Swim() {
        std::cout << name << " is swiming" << std::endl;
        oxygen -= 5;
        swimSpeed += 5;
    }
    void ShowStats() {
        Pokemon::ShowStats();
        std::cout << "Oxygen: " << oxygen << std::endl <<
            "Swim Speed: " << swimSpeed << std::endl;
    }
    void Attack(Pokemon* oponent) override {
        std::cout << this->name << " use Aqua Jet" << std::endl;

        if (oponent->GetWeakness() == this->type)
        {
            oponent->GetHitted(attack * 2);
            std::cout << "Its very efective" << std::endl;
            Sleep(1444);
            system("CLS");
        }

        else oponent->GetHitted(attack);
    }
};

class Plant : public Pokemon {
public:
    //Constructores
    Plant() : Pokemon() {
        this->name = "Bulbasaur";
        this->type = "Plant";
        this->weakness = "Fire";
        this->color = "Green";
        this->attack = 48.f;
        this->health = 130;
    }
    Plant(std::string name, std::string color, float attack, float health, int stamina, int walkSpeed, std::string type = "") : Pokemon(name, type, color, attack, health) {
        this->type = "Plant";
        this->weakness = "Fire";
        this->name = name;
        this->color = color;
        this->attack = attack;
        this->health = health;
        this->stamina = stamina;
        this->walkSpeed = walkSpeed;
    }
private:
    //Propiedades
    int stamina = 0;
    int walkSpeed = 0;
public:
    //Getters
    int GetStamina() {
        return stamina;
    }
    int GetWalkSpeed() {
        return walkSpeed;
    }
    //Setters
    void SetStamina(int stamina) {
        this->stamina = stamina;
    }
    void SetWalkSpeed(int walkSpeed) {
        this->walkSpeed = walkSpeed;
    }
    //Metodos
    void Walk() {
        std::cout << name << " is walking" << std::endl;
        walkSpeed += 5;
        stamina -= 5;
    }
    void ShowStats() {
        Pokemon::ShowStats();
        std::cout << "Walk Speed: " << walkSpeed << std::endl <<
            "Stamina: " << stamina << std::endl;
    }
    void Attack(Pokemon* oponent) override {
        std::cout << this->name << " use Leaf Storm" << std::endl;

        if (oponent->GetWeakness() == this->type)
        {
            oponent->GetHitted(attack * 2);
            std::cout << "Its very efective" << std::endl;
            Sleep(1444);
            //system("CLS");
        }

        else oponent->GetHitted(attack);
    }
};

class Electric : public Pokemon {
public:
    //Constructores
    Electric() : Pokemon() {
        this->name = "Pikachu";
        this->type = "Electric";
        this->weakness = "";
        this->color = "Yellow";
        this->attack = 30.f;
        this->health = 120;
        this->electricResistance = 5;
        this->voltage = 100;
    }
    Electric(std::string name, std::string color, float attack, float health, int voltage, int electricResistance, std::string type = "") : Pokemon(name, type, color, attack, health) {
        this->type = "Electric";
        this->weakness = "";
        this->name = name;
        this->color = color;
        this->attack = attack;
        this->health = health;
        this->voltage = voltage;
        this->electricResistance = electricResistance;
    }
private:
    //Propiedades
    int electricResistance = 0;
    int voltage = 0;
public:
    //Getters
    int GetVoltage() {
        return voltage;
    }
    int GetElectricResistance() {
        return electricResistance;
    }
    //Setters
    void SetVoltage(int voltage) {
        this->voltage = voltage;
    }
    void SetElectricResistance(int electricResistance) {
        this->electricResistance = electricResistance;
    }
    //Metodos
    void TurnOnTheLight() {
        std::cout << name << " turned on the lights" << std::endl;
        voltage -= 5;
        electricResistance += 5;
    }
    void TurnOffTheLight() {
        std::cout << name << " turned off the lights" << std::endl;
        voltage += 5;
        electricResistance -= 5;
    }
    void ShowStats() {
        Pokemon::ShowStats();
        std::cout << "Voltage: " << voltage << std::endl <<
            "Electric Resistance: " << electricResistance << std::endl;
    }
    void Attack(Pokemon* oponent) override {
        std::cout << this->name << " use Thunder Punch" << std::endl;

        if (oponent->GetWeakness() == this->type)
        {
            oponent->GetHitted(attack * 2);
            std::cout << "Its very efective" << std::endl;
            Sleep(1444);
            system("CLS");
        }

        else oponent->GetHitted(attack);
    }
};

void EnemyTeamSelection(Pokemon** pokemonList, Pokemon** enemyTeam, int selection, int index) {
    switch (selection)
    {
    case 0:
        enemyTeam[index] = pokemonList[2];
        break;
    case 1:
        enemyTeam[index] = pokemonList[0];
        break;
    case 2:
        enemyTeam[index] = pokemonList[1];
        break;
    default:
        break;
    }
}

void PokemonSelection(Pokemon** pokemonList, Pokemon** playerTeam, Pokemon** enemyTeam, int index) {
    int selection{ 0 };

    std::cout << "Choose your pokemon of type " << pokemonList[0]->GetType() << std::endl;

    for (int i = 0; i < 3; i++)
    {
        std::cout << "[" << i << "] " << pokemonList[i]->GetName() << std::endl;
    }

    std::cin >> selection;

    EnemyTeamSelection(pokemonList, enemyTeam, selection, index);

    system("CLS");

    std::cout << "You have choosen " << pokemonList[selection]->GetName() << std::endl;

    Sleep(777);
    system("CLS");

    playerTeam[index] = pokemonList[selection];
}

Pokemon* ChoosePokemon(Pokemon** playerTeam) {
    int selection{ 0 };
    std::cout << "Choose your pokemon to fight:" << std::endl;

    for (int i = 0; i < 4; i++)
    {
        if (playerTeam[i]->GetIsAlive())
            std::cout << "[" << i << "] " << playerTeam[i]->GetName() << std::endl;
    }
    std::cin >> selection;

    if (selection > 3) {
        std::cout << "Please type a valid number" << std::endl;
        Sleep(777); ChoosePokemon(playerTeam);
    }
    else if (!playerTeam[selection]->GetIsAlive()) {
        std::cout << "Please select an alive pokemon" << std::endl;
        Sleep(777); ChoosePokemon(playerTeam);
    }
    else {
        std::cout << playerTeam[selection]->GetName() << " go fight!" << std::endl;
        return playerTeam[selection];
    }
}

Pokemon* Actions(Pokemon** playerTeam, Pokemon* playerActivePokemon, Pokemon* enemyActivePokemon) {
    int selection{ 0 };

    std::cout << "What are you going to do?" << std::endl;

    std::cout << "[0] Fight" << std::endl;

    if (pokemonsAlive > 1)
        std::cout << "[1] Change Pokemon" << std::endl;
    if (potions >= 1)
        std::cout << "[2] Heal" << std::endl;

    std::cin >> selection;

    switch (selection)
    {
    case 0:
        playerActivePokemon->Attack(enemyActivePokemon);
        break;
    case 1:
        if (pokemonsAlive > 1)
        {
            system("CLS");
            playerActivePokemon = ChoosePokemon(playerTeam);
            Sleep(1444);
            system("CLS");
        }
        else
        {
            std::cout << "You dont have pokemons enough\nTry again";
            Sleep(1444);
            system("CLS");
        }
        break;
    case 2:
        if (potions >= 1)
        {
            playerActivePokemon->Heal();
            potions--;
        }
        else
        {
            std::cout << "You dont have potions enough\nTry again";
            Sleep(1444);
            system("CLS");
        }
        break;
    default:
        std::cout << "Something went wrong \nTry again";
        Sleep(1444);
        system("CLS");
        return playerActivePokemon;
        break;
    }

    if (enemyActivePokemon->GetIsAlive())
        enemyActivePokemon->Attack(playerActivePokemon);

    if (!playerActivePokemon->GetIsAlive())
    {
        std::cout << "Your " << playerActivePokemon->GetName() << " has been defeated";
        Sleep(1444);
        --pokemonsAlive;

        if (pokemonsAlive > 0)
        {
            playerActivePokemon = ChoosePokemon(playerTeam);
        }
        system("CLS");
    }

    return playerActivePokemon;
}

int main()
{
    Fire charmander("Charmander", "Orange", 18.f, 39.f, 100, 100);
    Fire torchic("Torchic", "Orange", 15.f, 45.f, 100, 100);
    Fire chimchar("Chimchar", "Orange", 16.f, 44.f, 100, 100);

    Water squirtle("Squirtle", "Blue", 16.f, 44.f, 100, 20);
    Water mudkip("Mudkip", "Blue", 14.f, 50.f, 100, 20);
    Water piplup("Piplup", "Blue", 13.f, 53.f, 100, 20);

    Plant bulbasaur("Bulbasaur", "Green", 13.f, 45.f, 100, 30);
    Plant treecko("Treecko", "Green", 20.f, 40.f, 100, 30);
    Plant turtwig("Turtwig", "Green", 21.f, 55.f, 100, 20);

    Electric pikachu("Pikachu", "Yellow", 15.f, 35.f, 5, 330);
    Electric voltorb("Voltorb", "Red/White", 20.f, 40.f, 5, 330);
    Electric jolteon("Jolteon", "Yellow/White", 17.f, 45.f, 5, 330);

    Pokemon* firePokemons[3] = { &charmander, &torchic, &chimchar };
    Pokemon* waterPokemons[3] = { &squirtle, &mudkip, &piplup };
    Pokemon* plantPokemons[3] = { &bulbasaur, &treecko, &turtwig };
    Pokemon* electricPokemons[3] = { &pikachu, &voltorb, &jolteon };

    Pokemon* playerTeam[4];
    Pokemon* enemyTeam[4];

    Pokemon* playerActivePokemon;
    Pokemon* enemyActivePokemon;

    int enemyIndex{ 0 };

    PokemonSelection(firePokemons, playerTeam, enemyTeam, 0);
    PokemonSelection(waterPokemons, playerTeam, enemyTeam, 1);
    PokemonSelection(plantPokemons, playerTeam, enemyTeam, 2);
    PokemonSelection(electricPokemons, playerTeam, enemyTeam, 3);

    std::cout << "Your Team:" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << playerTeam[i]->GetName() << std::endl;
    }
    Sleep(1444);
    system("CLS");

    std::cout << "Rival Team:" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << enemyTeam[i]->GetName() << std::endl;
    }
    Sleep(1444);
    system("CLS");

    playerActivePokemon = ChoosePokemon(playerTeam);

    Sleep(1444);
    system("CLS");

    enemyActivePokemon = enemyTeam[enemyIndex];

    while (pokemonsAlive > 0 || enemyTeam[3]->GetIsAlive()) {
        std::cout << pokemonsAlive;
        playerActivePokemon = Actions(playerTeam, playerActivePokemon, enemyActivePokemon);

        if (!enemyActivePokemon->GetIsAlive() && enemyActivePokemon != enemyTeam[3]) {
            enemyIndex++;
            std::cout << "Your " << playerActivePokemon->GetName() << " defeated " << enemyActivePokemon->GetName() << "\nYour enemy sent to " << enemyTeam[enemyIndex]->GetName();
            Sleep(1444);
            system("CLS");
            enemyActivePokemon = enemyTeam[enemyIndex];
        }
        else if (!enemyTeam[3]->GetIsAlive()) {
            std::cout << "Your " << playerActivePokemon->GetName() << " defeated " << enemyActivePokemon->GetName();
            Sleep(1444);
            system("CLS");
            std::cout << "You won";
            break;
        }
        else if (pokemonsAlive <= 0) {
            system("CLS");
            std::cout << "You loose";
            break;
        }
    }

    delete(firePokemons); delete(waterPokemons); delete(plantPokemons); delete(electricPokemons);
    delete(playerTeam); delete(enemyTeam);
    delete(playerActivePokemon); delete(enemyActivePokemon);
}