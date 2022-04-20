//
// Created by sagiv on 2/12/2022.
//

#ifndef BRIDGESORTER_ABSTRACTFACTORY_CPP
#define BRIDGESORTER_ABSTRACTFACTORY_CPP

#include <iostream>

class Sword {
public:
};

class lightSword : public Sword {
public:
    lightSword() : Sword() {
        std::cout << " ^\n"
                     " |\n"
                     " |\n"
                     " |\n"
                     "o+o\n"
                     " 0" << std::endl;
    }
};

class middleAgeSword : public Sword {
public:
    middleAgeSword() : Sword() {
        std::cout << "       )         \n"
                     "          (            \n"
                     "        '    }      \n"
                     "      (    '      \n"
                     "     '      (   \n"
                     "      )  |    ) \n"
                     "    '   /|\\    `\n"
                     "   )   / | \\  ` )   \n"
                     "  {    | | |  {   \n"
                     " }     | | |  .\n"
                     "  '    | | |    )\n"
                     " (    /| | |\\    .\n"
                     "  .  / | | | \\  (\n"
                     "}    \\ \\ | / /  .        \n"
                     " (    \\ `-' /    }\n"
                     " '    / ,-. \\    ' \n"
                     "  }  / / | \\ \\  }\n"
                     " '   \\ | | | /   } \n"
                     "  (   \\| | |/  (\n"
                     "    )  | | |  )\n"
                     "    .  | | |  '\n"
                     "       J | L\n"
                     " /|    J_|_L    |\\\n"
                     " \\ \\___/ o \\___/ /\n"
                     "  \\_____ _ _____/\n"
                     "        |-|\n"
                     "        |-|\n"
                     "        |-|\n"
                     "       ,'-'.\n"
                     "       '---'" << std::endl;
    }
};


class Shield {
public:
};

class middleAgesShield : public Shield {
public:
    middleAgesShield() : Shield() {
        std::cout << "|<><><>     |  |    <><><>|\n"
                     "|<>         |  |        <>|\n"
                     "|           |  |          |\n"
                     "|  (______ <\\-/> ______)  |\n"
                     "|  /_.-=-.\\| \" |/.-=-._\\  | \n"
                     "|   /_    \\(o_o)/    _\\   |\n"
                     "|    /_  /\\/ ^ \\/\\  _\\    |\n"
                     "|      \\/ | / \\ | \\/      |\n"
                     "|_______ /((( )))\\ _______|\n"
                     "|      __\\ \\___/ /__      |\n"
                     "|--- (((---'   '---))) ---|\n"
                     "|           |  |          |\n"
                     "|           |  |          |\n"
                     ":           |  |          :     \n"
                     " \\<>        |  |       <>/      \n"
                     "  \\<>       |  |      <>/       \n"
                     "   \\<>      |  |     <>/       \n"
                     "    `\\<>    |  |   <>/'         \n"
                     "      `\\<>  |  |  <>/'         \n"
                     "        `\\<>|  |<>/'         \n"
                     "          `-.  .-`           \n"
                     "            '--'" << std::endl;

    }
};

class StarWarsShield : public Shield {
public:
    StarWarsShield() : Shield() {
        std::cout << "           _ -  / -  _\n"
                     "         -      /       -\n"
                     "       -        /         -\n"
                     "     -          /           -\n"
                     "    _           /            _\n"
                     "    _           /             _\n"
                     "  ( / / / / / / 0/ / / / / / / )\n"
                     "  0 _           /            _ 0\n"
                     "  #  _          /           _  #\n"
                     "  #   _         /          _   #\n"
                     "  #     _       /        _     #\n"
                     "  0        -  _ / _   -        0\n"
                     " /I\\            0             /I\\\n"
                     "//I\\\\           #            //I\\\\\n"
                     "//I\\\\           #            //I\\\\\n"
                     "//I\\\\           0            //I\\\\\n"
                     " /I\\           /I\\            /I\\\n"
                     "  v           //I\\\\            v\n"
                     "              //I\\\\\n"
                     "              //I\\\\\n"
                     "               /I\\" << std::endl;
    }
};


class Character {
public:
    virtual ~Character() = default;

    virtual Sword *getSword() const = 0;

    virtual Shield *getShield() const = 0;

};

class CharacterSW : public Character {
public:
    CharacterSW(): Character(){
        std::cout << "             .               .    .          .              .   .         .\n"
                     "               _________________      ____         __________\n"
                     " .       .    /                 |    /    \\    .  |          \\\n"
                     "     .       /    ______   _____| . /      \\      |    ___    |     .     .\n"
                     "             \\    \\    |   |       /   /\\   \\     |   |___>   |\n"
                     "           .  \\    \\   |   |      /   /__\\   \\  . |         _/               .\n"
                     " .     ________>    |  |   | .   /            \\   |   |\\    \\_______    .\n"
                     "      |            /   |   |    /    ______    \\  |   | \\           |\n"
                     "      |___________/    |___|   /____/      \\____\\ |___|  \\__________|    .\n"
                     "  .     ____    __  . _____   ____      .  __________   .  _________\n"
                     "       \\    \\  /  \\  /    /  /    \\       |          \\    /         |      .\n"
                     "        \\    \\/    \\/    /  /      \\      |    ___    |  /    ______|  .\n"
                     "         \\              /  /   /\\   \\ .   |   |___>   |  \\    \\\n"
                     "   .      \\            /  /   /__\\   \\    |         _/.   \\    \\            +\n"
                     "           \\    /\\    /  /            \\   |   |\\    \\______>    |   .\n"
                     "            \\  /  \\  /  /    ______    \\  |   | \\              /          .\n"
                     " .       .   \\/    \\/  /____/      \\____\\ |___|  \\____________/  LS\n"
                     "                               .                                        .\n"
                     "     .                           .         .               .                " << std::endl;
    }
    Sword *getSword() const {
        return new lightSword();
    }

    Shield *getShield() const {
        return new StarWarsShield;
    }

};

class CharacterMA : public Character {
public:
    CharacterMA(): Character(){
        std::cout << "\n"
                     " _______ _________ ______   ______   _        _______          _______  _______  _______  _______ \n"
                     "(       )\\__   __/(  __  \\ (  __  \\ ( \\      (  ____ \\        (  ___  )(  ____ \\(  ____ \\(  ____ \\\n"
                     "| () () |   ) (   | (  \\  )| (  \\  )| (      | (    \\/        | (   ) || (    \\/| (    \\/| (    \\/\n"
                     "| || || |   | |   | |   ) || |   ) || |      | (__            | (___) || |      | (__    | (_____ \n"
                     "| |(_)| |   | |   | |   | || |   | || |      |  __)           |  ___  || | ____ |  __)   (_____  )\n"
                     "| |   | |   | |   | |   ) || |   ) || |      | (              | (   ) || | \\_  )| (            ) |\n"
                     "| )   ( |___) (___| (__/  )| (__/  )| (____/\\| (____/\\        | )   ( || (___) || (____/\\/\\____) |\n"
                     "|/     \\|\\_______/(______/ (______/ (_______/(_______/        |/     \\|(_______)(_______/\\_______)\n"
                     "                                                                                                  "
                  << std::endl;
    }
    Sword *getSword() const {
        return new middleAgeSword();
    }

    Shield *getShield() const {
        return new middleAgesShield;
    }

};

void runAbstractFactory(){
    CharacterSW *sw = new CharacterSW();
    sw->getSword();
    sw->getShield();
    delete(sw);
    CharacterMA *ma = new CharacterMA();
    ma->getSword();
    ma->getShield();
    delete(ma);
}
#endif //BRIDGESORTER_ABSTRACTFACTORY_CPP
