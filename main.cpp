#define SDL_MAIN_HANDLED
#include "lib.h"
#include "dynamic_lib.h"

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* win = SDL_CreateWindow("Lazarus", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (win == NULL) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == NULL) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    SDL_Event e;
    bool quit = false;

    //initialization player and list of the platforms
    Player player(350, 250, 100, 100);

    std::vector<Object> Lplatform = {
        Object(400, 550, 400, 50),
        Object(700, 400, 100, 150)
        
    };
    //Object object(700, 400, 100, 150);

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
                quit = true;
            }
            
            player.handleEvent(e);

        }
        //TODO: tablica kierunk�w wileko�ci ile jest obiekt�w (vector.size()) i na podstawie tablicy sprawdza� 
        char direction = 'N';
        std::vector<char> directionList;
        //Check every possible collision with all objects at the screen
        for (auto obj : Lplatform) {
            direction = directionOfCollision(player, obj, isCollision(player, obj));
            directionList.push_back(direction);
            std::cout << direction << std::endl;
        }
        
        player.update(directionList);

        //screen cleaning
        SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
        SDL_RenderClear(ren);

        //player new position render
        for (auto obj : Lplatform) obj.render(ren);
        player.render(ren);

        //screen update
        SDL_RenderPresent(ren);
        //SDL_Delay(100);
    }

    //cleaning
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
