#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>

int main()
{
    sf::RenderWindow app(sf::VideoMode(1920, 1080), "SFML window");

    sf::VertexArray linesArray(sf::LinesStrip, 0);
    const sf::Vector2f centre(960, 540);
    const float radius = 300.0f;

    srand(std::time(NULL));

    std::clock_t start = std::clock();
    double duration;

    while (app.isOpen())
    {
        sf::Event event;
        while (app.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                app.close();
        }

        duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

        if(duration < .05)
            continue;

        if(linesArray.getVertexCount() > 300)
            linesArray.clear();

        int randDegree = rand() % 360;

        double randx = centre.x + radius * cos(randDegree);
        double randy = centre.y + radius * sin(randDegree);
        sf::Vector2f randomCircumferancePoint(randx, randy);

        sf::Vertex newVertex(randomCircumferancePoint, sf::Color(rand()%255, rand()%255, rand()%255));
        linesArray.append(newVertex);

        start = std::clock();
        duration = 0;


        std::cerr << "Verts:\t" << linesArray.getVertexCount() << "\r";

        app.clear();
        app.draw(linesArray);
        app.display();
    }

    return EXIT_SUCCESS;
}
