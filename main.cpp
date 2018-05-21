//
//  main.cpp
//  vigenere
//
//  Created by Abdullah Eryuzlu on 14.05.2018.
//  Copyright © 2018 abdullaheryuzlu. All rights reserved.
//

#include <iostream>
#include "vigenere.hpp"
#include "vigenere_cracker.hpp"
#include "pair.cpp"

int main() {

    std::string output = Vigenere::encrypt("Do to be agreeable conveying oh assurance. Wicket longer admire do barton vanity itself do in it. Preferred to sportsmen it engrossed listening. Park gate sell they west hard for the. Abode stuff noisy manor blush yet the far. Up colonel so between removed so do. Years use place decay sex worth drift age. Men lasting out end article express fortune demands own charmed. About are are money ask how seven.Shot what able cold new the see hold. Friendly as an betrayed formerly he. Morning because as to society behaved moments. Put ladies design mrs sister was. Play on hill felt john no gate. Am passed figure to marked in. Prosperous middletons is ye inhabiting as assistance me especially. For looking two cousins regular amongst.Unwilling sportsmen he in questions september therefore described so. Attacks may set few believe moments was. Reasonably how possession shy way introduced age inquietude. Missed he engage no exeter of. Still tried means we aware order among on. Eldest father can design tastes did joy settle. Roused future he ye an marked. Arose mr rapid in so vexed words. Gay welcome led add lasting chiefly say looking.Speedily say has suitable disposal add boy. On forth doubt miles of child. Exercise joy man children rejoiced. Yet uncommonly his ten who diminution astonished. Demesne new manners savings staying had. Under folly balls death own point now men. Match way these she avoid see death. She whose drift their fat off.Woody equal ask saw sir weeks aware decay. Entrance prospect removing we packages strictly is no smallest he. For hopes may chief get hours day rooms. Oh no turned behind polite piqued enough at. Forbade few through inquiry blushes you. Cousin no itself eldest it in dinner latter missed no. Boisterous estimating interested collecting get conviction friendship say boy. Him mrs shy article smiling respect opinion excited. Welcomed humoured rejoiced peculiar to in an.Is we miles ready he might going. Own books built put civil fully blind fanny. Projection appearance at of admiration no. As he totally cousins warrant besides ashamed do. Therefore by applauded acuteness supported affection it. Except had sex limits county enough the figure former add. Do sang my he next mr soon. It merely waited do unable.View fine me gone this name an rank. Compact greater and demands mrs the parlors. Park be fine easy am size away. Him and fine bred knew. At of hardly sister favour. As society explain country raising weather of. Sentiments nor everything off out uncommonly partiality bed.Meant balls it if up doubt small purse. Required his you put the outlived answered position. An pleasure exertion if believed provided to. All led out world these music while asked. Paid mind even sons does he door no. Attended overcame repeated it is perceive marianne in. In am think on style child of. Servants moreover in sensible he it ye possible.Mind what no by kept. Celebrated no he decisively thoroughly. Our asked sex point her she seems. New plenty she horses parish design you. Stuff sight equal of my woody. Him children bringing goodness suitable she entirely put far daughter.Advantage old had otherwise sincerity dependent additions. It in adapted natural hastily is justice. Six draw you him full not mean evil. Prepare garrets it expense windows shewing do an. She projection advantages resolution son indulgence. Part sure on no long life am at ever. In songs above he as drawn to. Gay was outlived peculiar rendered led six.", "NEMLENAND");

    std::string xd = "JWMPJCLRJZIFZABHXAEHUIZVBHGGQKYOBNCALRIHBVHORCHJZZVIMQLQQYLEUZTYHYJVPOPHYZNUWUHYUBHACOENSFTGYVQPRPRJQAWTRYKANCQYOBNJALIJVWZMKBLIAFQKSYNGTDDYZTLSEMVKVWZMHAZWACULKQANJQWQBLJYGEEVLAIPPNCXLAWVWZMKZRBEJDJVYEEEDDZCWASZTVZVPQMLZCNCWJTGBVSCYYHBYZAXRGXOYJTNFVEBYKWPQEZLVCSNFAKPJMFEBLNATYUKMBAHYLIBGTKMYHRSAAHOZDLXJFDMQLQAMPHYJHUIIQAVGATLHJPTGGLAHZVBPZQUIJAZDNZCMHQLQJCANQNPIJZZBYKHYAJBEQXEZUNHDEPLPFYQHWZWNUVJPOPHYZNZASLJJZCXYBPZUAMYGMJAOIWECCZZVBCAAYEZCEVZOAHXMRPZJGYNCCDPNHDLYHZYKDJPFILXSANABVIMZNLUJMCVZOGKOAGFJHMMGTQAPJQJEATFCCALYMOKQAZPZFCCARDCECJUZFDAGDSIXATBLXJHFHZRYHKBCJUEZBPMOIJDYQNLZONMLEPYSYYYCSZLZNRGBFIJWRZTSHMVYBXZKSNYVKGHLOPBRPKQESQWIHETMTYNTLJHJHPKWTGOGCBWEAJFCCAFYABVINEZBPMVROYCSCKTKGZMMMMDAPLAKJAPJXYORCIUEWXNYTGYJOYJTNFVEBYKAVHOFUKPFJHUPEHNPQYQBLEGYJWMEPPEXJZMXYGMIBTDJQLEWGGYKPJYFYKJMZVJXMYJPRJQILCZAYMGGAEDWZOQXEZNBYURFJRZZQXVFJRUBEBVDEYZJZOAUJMCGQKZPLNPUTIPMSNQTYJTNKUAHMYVHGZLIUKFJFCMYVRHMJIWVWIVCMSIBOGBWXHTKGLATCXYTTJJZPVJVVVVXPBQESZIVEMARDSZRIJCZPNHDLYHZYOBNFTNIJCANQNPIJZQUCJQPHOHCGASGJMTKJFORAPIJZVKGYURFJRZKQBLXJQUMCJCDZZQHSZLAXRGXJQWQGLJVJPMRDXUCJUZVGHUDWBBJQWQGLYKBIVYPGJZRPNWHMPYKATAJFCWHRPTRYGMYAAPPQXVFJPHAFYAPPPKKFJVYGGGVOQJQESZLKMBVADOHTZQKMGEEPBRZCPCOQPBYMPJRILVCZQWMYIRFBOGEQXVFSBYKJMCHOQPEAAKHLQPLCIPPAQJUFVAMVPFCJUZQKGSBQGFATOPMZNLUJCOPBRZCREQFGBZBAHYFZLQBEXUFPSSRAIPPNRALCKFAIXLCQZAHZMMGDZPPJXEHJHXCAHYFZLQGLWBPBABAMPBBJZNFIXALCNZCCEIZNVAREGLARJJWYWPZZMVVVAPPSXLXPBYVPTVPRPESYJATKHBLOOCWRLHXBPBAYHCACHXCZPFDAELRANQXLRGBZMSXQTYUSNYWAUKVWZMPCWRLHXBPBAYHCACCCXDAGUMQBTMZKQASJJGUBZJCELCCACFUZKFTSXUKQDLELOEMPLEILLVVTKBYBGHOPGJSNYTWNYAMGRTBKQNHXAHGKPJFABVINYHAMIJPPBOIQQRLSTMHQABOQBBDWFTVMCEYQIHZPFGPAMYSYNTLJHUNHREPQYLYZEFFKHZMQLQQYJUSTWSBEPBRZCIZHDWICZAUDAJOZGLJQUGRSLOYULNHDJKMANQKPWCXZVFPMSIVDJHYJZPNHDLYHZYPIZPZWFYXGWCXYKUESZUFYMPJPQXTWFZWFYVWFQSQBLEEXLUYDEZSMIJHHSDJHXCUPCSZCNHEIAKNMRFMJQNKXQKSYKAMQSGULCZVKGYGMHOOGCSRHFGGYIEFZOZPQXVFJLMVPPCXOCSHFFMKUBATKJQCRRHNZGBAIQDZKSAQGJFCMOIJDYSNTQEBYKAMDCQYSJZRLKKMMGMKFBZXAVWLX";
    
//    UnsignedPair<float> freqs;
//    const std::string m_DEFAULT_PATH = "/Users/abdullaheryuzlu/Desktop/vigenere/vigenere/default_freq_table.txt";
//    std::string file_path = m_DEFAULT_PATH;
//    std::string path = file_path == "" ? m_DEFAULT_PATH : file_path;
//    std::ifstream infile(path);
//    char a; float b;
//    while (infile >> a >> b) {
//        freqs.set_value(a, b);
//    }
//
//    VigenereCracker vc(xd, freqs);
//    vc.crack();

    std::ifstream infile("/Users/abdullaheryuzlu/Desktop/vigenere/vigenere/xd.txt");
    std::string a;
    long double count = 0;
    std::vector<std::string> decodeds;
    while (infile >> a) {
        std::string decoded = Vigenere::decrypt(xd, a);
        if (decoded.find("EVERY") != std::string::npos) {
            std::cout << decoded << std::endl;
        }
        count ++;
    }

    return 0;
}
