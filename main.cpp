#include <SFML/Graphics.hpp>
#include <iostream>
#include <unistd.h>

sf::RenderWindow window(sf::VideoMode(600, 600), "SFML Test");

struct bod{
    int x;
    int y;
    bool empty;
    bool kolecko;
};
bod body[3][3]=
{
    {{100, 100, true, false}, {300, 100, true, false}, {500, 100, true, false}},
    {{100, 300, true, false}, {300, 300, true, false}, {500, 300, true, false}},
    {{100, 500, true, false}, {300, 500, true, false}, {500, 500, true, false}}
};

struct board{
    bod body[3][3];
};
bool o = false;
int tahy = 0;
sf::Font font;
//vykresleni zakladu 
void zaklad(sf::RenderWindow& window){
    sf::RectangleShape first( sf::Vector2f(10, 600) );
    first.setFillColor(sf::Color::White);
    first.setPosition(195, 0);
    window.draw(first);

    sf::RectangleShape second( sf::Vector2f(10, 600) );
    second.setFillColor(sf::Color::White);
    second.setPosition(395, 0);
    window.draw(second);

    sf::RectangleShape third( sf::Vector2f(600, 10) );
    third.setFillColor(sf::Color::White);
    third.setPosition(0, 195);
    window.draw(third);

    sf::RectangleShape fourth( sf::Vector2f(600, 10) );
    fourth.setFillColor(sf::Color::White);
    fourth.setPosition(0, 395);
    window.draw(fourth);

}
void draw(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            bod our = body[i][j];
            if(!our.empty){
                if (our.kolecko) {
                    sf::CircleShape kruh(60);
                    kruh.setFillColor(sf::Color::Transparent);
                    kruh.setOutlineColor(sf::Color::Blue);
                    kruh.setOutlineThickness(8);
                    kruh.setOrigin(60, 60);
                    kruh.setPosition(our.x -3, our.y -3);
                    sf::CircleShape kruh2(60);
                    kruh2.setFillColor(sf::Color::Transparent);
                    kruh2.setOutlineColor(sf::Color::Magenta);
                    kruh2.setOutlineThickness(8);
                    kruh2.setOrigin(60, 60);
                    kruh2.setPosition(our.x + 3, our.y + 3);

                    window.draw(kruh2);
                    window.draw(kruh);

                    std::cout << "Drawej kolecko na: " << our.x << ", " << our.y << std::endl;
                }
                else{
                    float size = 100.f;   // délka ramen křížku
                    float thickness = 10.f;

                    sf::RectangleShape line1({size, thickness});
                    line1.setFillColor(sf::Color::Red);
                    line1.setOrigin(size / 2.f, thickness / 2.f); // střed obdélníku
                    line1.setPosition(our.x, our.y);
                    line1.setRotation(45.f);

                    sf::RectangleShape line2({size, thickness});
                    line2.setFillColor(sf::Color::Green);
                    line2.setOrigin(size / 2.f, thickness / 2.f);
                    line2.setPosition(our.x, our.y);
                    line2.setRotation(-45.f);

                    window.draw(line1);
                    window.draw(line2);
                    std::cout << "Drawej kriz na: " << our.x << ", " << our.y << std::endl;
                }
            }
        }
    }
}
//grafika po vyhrani kolecka
void vyhra_kolecko(){
    sf::Text text;
    text.setFont(font);
    text.setString("Vyhral hrac s koleckem!");
    text.setCharacterSize(48); // px
    text.setFillColor(sf::Color::Blue);
    text.setPosition(10, 300);

    window.clear();
    window.draw(text);
    window.display();
    sleep(2);
    sf::CircleShape kruh(200);
    kruh.setFillColor(sf::Color::Transparent);
    kruh.setOutlineColor(sf::Color::Blue);
    kruh.setOutlineThickness(18);
    kruh.setOrigin(200, 200);
    kruh.setPosition(295, 295);
    ////
    sf::CircleShape kruh2(200);
    kruh2.setFillColor(sf::Color::Transparent);
    kruh2.setOutlineColor(sf::Color::Magenta);
    kruh2.setOutlineThickness(18);
    kruh2.setOrigin(200, 200);
    kruh2.setPosition(305, 305);
    window.clear();
    window.draw(kruh2);
    window.draw(kruh);
    window.display();
    sleep(3);
    window.close();
}

void vyhra_kriz(){
    sf::Text text;
    text.setFont(font);
    text.setString("Vyhral hrac s krizkem!");
    text.setCharacterSize(48); // px
    text.setFillColor(sf::Color::Red);
    text.setPosition(30, 300);
    window.clear();
    window.draw(text);
    window.display();
    sleep(2);
    float size = 500.f;   // délka ramen křížku
    float thickness = 30.f;

    sf::RectangleShape line1({size, thickness});
    line1.setFillColor(sf::Color::Red);
    line1.setOrigin(size / 2.f, thickness / 2.f); // střed obdélníku
    line1.setPosition(300, 300);
    line1.setRotation(45.f);

    sf::RectangleShape line2({size, thickness});
    line2.setFillColor(sf::Color::Green);
    line2.setOrigin(size / 2.f, thickness / 2.f);
    line2.setPosition(300, 300);
    line2.setRotation(-45.f);

    window.clear();
    window.draw(line1);
    window.draw(line2);
    window.display();
    sleep(3);
    window.close();
}

void plichta(){
    sf::Text text;
    text.setFont(font);
    text.setString("Plichta");
    text.setCharacterSize(68); // px
    text.setFillColor(sf::Color::Green);
    text.setPosition(140, 275);

    window.clear();
    window.draw(text);
    window.display();
    sleep(3);
    window.close();
}

// zkontrolujeme, jestli jsme vyhrali
void kontrola(){
    //horizontalne
    for(int i=0; i<3; i++){
        if(body[0][i].kolecko && body[1][i].kolecko && body[2][i].kolecko && !body[0][i].empty && !body[1][i].empty && !body[2][i].empty){
            std::cout << "Vyhral hrac s koleckem!" << std::endl;
            tahy = 9; // ukončíme hru;
            vyhra_kolecko();
            return;
        }
        if(!body[0][i].kolecko && !body[1][i].kolecko && !body[2][i].kolecko && !body[0][i].empty && !body[1][i].empty && !body[2][i].empty){
            std::cout << "Vyhral hrac s krizkem!" << std::endl;
            tahy = 9; // ukončíme hru
            vyhra_kriz();
            return;
        }
    }
    //vertikalne
    for(int i=0; i<3; i++){
        if(body[i][0].kolecko && body[i][1].kolecko && body[i][2].kolecko && !body[i][0].empty && !body[i][1].empty && !body[i][2].empty){
            std::cout << "Vyhral hrac s koleckem!" << std::endl;
            tahy = 9; // ukončíme hru
            vyhra_kolecko();
            return;
        }
        if(!body[i][0].kolecko && !body[i][1].kolecko && !body[i][2].kolecko && !body[i][0].empty && !body[i][1].empty && !body[i][2].empty){
            std::cout << "Vyhral hrac s krizkem!" << std::endl;
            tahy = 9; // ukončíme hru
            vyhra_kriz();
            return;
        }
    }
    //uhlopricka
    if(body[0][0].kolecko && body[1][1].kolecko && body[2][2].kolecko && !body[0][0].empty && !body[1][1].empty && !body[2][2].empty){
        std::cout << "Vyhral hrac s koleckem!" << std::endl;
        tahy = 9; // ukončíme hru
        vyhra_kolecko();
        return;
    }
    if(!body[0][0].kolecko && !body[1][1].kolecko && !body[2][2].kolecko && !body[0][0].empty && !body[1][1].empty && !body[2][2].empty){
        std::cout << "Vyhral hrac s krizkem!" << std::endl;
        tahy = 9; // ukončíme hru
        vyhra_kriz();
        return;
    }
    if(body[0][2].kolecko && body[1][1].kolecko && body[2][0].kolecko && !body[0][2].empty && !body[1][1].empty && !body[2][0].empty){
        std::cout << "Vyhral hrac s koleckem!" << std::endl;
        tahy = 9; // ukončíme hru
        vyhra_kolecko();
        return;
    }
    if(!body[0][2].kolecko && !body[1][1].kolecko && !body[2][0].kolecko && !body[0][2].empty && !body[1][1].empty && !body[2][0].empty){
        std::cout << "Vyhral hrac s krizkem!" << std::endl;
        tahy = 9; // ukončíme hru
        vyhra_kriz();
        return;
    }
}

// vykresleni krizku nebo koleck
void play(sf::Vector2i pixelPos) {
    int col = pixelPos.x / 200;
    int row = pixelPos.y / 200;
    std::cout << "Clicked at: " << col << ", " << row << std::endl;
    if (col >= 0 && col < 3 && row >= 0 && row < 3) {
        if (body[row][col].empty) {
            body[row][col].empty = false;
            body[row][col].kolecko = o; // nebo false pro krizky
            std::cout << "Placing " << (o ? "circle" : "cross") << " at: " << col << ", " << row << std::endl;
            o = !o;  // Přepni hráče
            tahy++;
            std::cout << "Total moves: " << tahy << std::endl;
            draw();
            kontrola();
            if(tahy == 9) {
                plichta();
            }
        }
    }
}
// always start x
int main() {
    if (!font.loadFromFile("assets/fonts/DejaVuSans.ttf")) {
        std::cout << "Nepodarilo se nacist font!\n";
    }
    // 2) Vytvoř text
    sf::Text text;
    text.setFont(font);
    text.setString("Zaciname");
    text.setCharacterSize(88); // px
    text.setFillColor(sf::Color::Blue);
    text.setOutlineColor(sf::Color::Red);
    text.setOutlineThickness(4);
    text.setPosition(110, 250);
    window.clear();
    zaklad(window);
    window.draw(text);
    window.display();
    sleep(0.5);

    while (window.isOpen()) {
        sf::Event ev;
        while (window.pollEvent(ev)) {
            if (ev.type == sf::Event::Closed) window.close();

            if (ev.type == sf::Event::MouseButtonPressed &&
                ev.mouseButton.button == sf::Mouse::Left && tahy < 9) {
                // POZOR: pokud používáš View, převeď pixely na "světové" souřadnice:
                sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
                std::cout << "Pixel position: " << pixelPos.x << ", " << pixelPos.y << std::endl;
                window.clear();
                play(pixelPos);
                zaklad(window);
                window.display();
            }
        }
    }
}
