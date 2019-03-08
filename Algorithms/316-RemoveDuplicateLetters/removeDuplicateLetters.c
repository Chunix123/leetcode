//
// Created by zyc on 3/7/19.
//
/* 316. Remove Duplicate Letters
 * Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
    Example 1:
      Input: "bcabc"
      Output: "abc"
    Example 2:
      Input: "cbacdcbc"
      Output: "acdb"
 */
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "removeDuplicateLetters.h"


// BUG Not use
/*
char* reverseStr(char *s)
{
    char *h = s;
    char *t = s;
    char ch;

    while(*t++);
    t--;
    t--;

    while(h < t)
    {
        ch = *h;
        *h++ = *t;
        *t-- = ch;
    }
    //printf("%s\n", s);

    return s;
}

char* removeDuplicateLetters(char* s)
{
    s = reverseStr(s);
    printf("%s\n", s);

    int i, j, k = 0, m;
    int len = strlen(s) - 1;
    int ss[len];
    bool flag = true;

    memset(ss, 0, len);

    for(i = 0; i <= len; i++)
    {
        for(j = i + 1; j <= len; j++)
        {
            printf("%c%c ", s[i], s[j]);
            if(s[i] == s[j])
            {
                printf("--> %d %c --> ", j, s[i]);
                printf("%d %d ", i, ss[i]);
                flag = true;

                for(m = 0; m < k; m++)
                {
                    if(ss[m] == i)
                    {
                        flag = false;
                    }
                }
                if(flag)
                {
                    ss[k++] = j;
                    printf("ss[%d]: %d\n", k - 1, j);
                }
                //ss[k++] = j;
            }
        }
        printf("\n");
    }

    int n = 0, lens = k--;//strlen(ss);
    char sr[len];

    for(i = 0; i < lens; i++)
    {
        printf("%d", ss[i]);
    }
    printf("\n");

    memset(sr, 0, len);
    printf("%s lens: %d\n", s, lens);

    for(i = 0; i <= len; i++)
    {
        flag = true;
        for(j = 0; j < lens; j++)
        {
            if(i == ss[j])
            {
                flag = false;
            }
        }
        if(flag)
        {
            printf("%d\n", i);
            sr[n++] = s[i];
        }
    }

    printf("%s\n", sr);
    s = reverseStr(sr);
    printf("%s\n", sr);

    return s;
}
*/

// BUG Not use
/*
int getLetters(char* s, int pos)
{
    int i, len = strlen(s);
    int pBoolean[128];

    memset(pBoolean, 0, 128);

    for(i = 0; i < pos; i++)
    {
        pBoolean[s[i] - 'a'] = 1;
    }

    for(i = pos; i < len; i++)
    {
        int sum = s[i] - 'a';
        //printf("%d %d %s %c %d\n", pos, i, s, s[i], sum);
        pBoolean[sum] = 0;
    }

    for(i = 0; i < 26; i++)
    {
        if(pBoolean[i])
        {
            return 0;
        }
    }

    return 1;
}

char* removeDuplicateLetters(char* s)
{
    if(s == NULL)
        return s;

    int flag;
    int i, j, m, n = 0, len = strlen(s);

    if(len <= 1)
        return s;

    char str[len+1];
    char *stm = malloc(len * sizeof(char*));

    memset(str, 0, len);
    memset(stm, 0, len);

    for(m = 0; m < len; m++)
    {
        n = 0;
        for(i = m; i < len; i++)
        {
            flag = 1;
            for(j = 0; j < n; j++)
            {
                if(s[i] == str[j])
                    flag = 0;
            }
            if(flag)
                str[n++] = s[i];
        }
        str[n] = '\0';

        if(m == 0)
        {
            strcpy(stm, str);
        }
        printf("%s %s\n", str, stm);

        int l, isLetters = getLetters(s, m);
        if(isLetters)
        {
            for(l = 0; l < strlen(stm); l++)
            {
                if(stm[l] - str[l] < 0)
                {
                    break;
                }
                if(stm[l] - str[l] > 0)
                {
                    strcpy(stm, str);
                    break;
                }
            }

        }
        //printf("%d %s\n", isLetters, stm);
    }

    //printf("%s %s\n", str, stm);

    return stm;
}
 */

/*
char* reverseStr(char *s)
{
    char *h = s;
    char *t = s;
    char ch;
    while(*t++);
    t--;
    t--;
    while(h < t)
    {
        ch = *h;
        *h++ = *t;
        *t-- = ch;
    }
    //printf("%s\n", s);
    return s;
}

char* removeDuplicateLetters(char* s)
{
    //printf("s: %s\n", s);

    //0.
    if(s == NULL)
        return s;

    int len = strlen(s);
    if(len <= 1)
        return s;

    //1.
    int i, j, n, numl = 0, numr = 0, pos = 0;
    for(i = 0; i < len; i++)
    {
        numr = s[i] - 'a';
        if(i == 0)
        {
            numl = numr;
            pos = i;
        }
        if(numl > numr)
        {
            numl = numr;
            pos = i;
        }
    }
    //printf("%d %c\n", pos, s[pos]);

    //2.
    bool flag = true;
    char stl[len];

    memset(stl, 0, len);
    n = 0;
    for(i = 0; i < pos; i++)
    {
        flag = true;
        for(j = 0; j < n; j++)
        {
            if(stl[j] == s[i])
                flag = false;
        }
        if(flag)
            stl[n++] = s[i];
    }
    stl[n] = '\0';
    //printf("stl: %d %s\n", n, stl);

    char str[len + 1];

    memset(str, 0, len);
    n = 0;
    for(i = pos; i < len; i++)
    {
        flag = true;
        for(j = 0; j < n; j++)
        {
            if(s[i] == str[j])
                flag = false;
        }
        if(flag)
            str[n++] = s[i];
    }
    str[n] = '\0';
    //printf("str: %d %s\n", n, str);

    //3.
    char stri[len * 2];
    n = 0;

    memset(stri, 0, len);
    for(i = 0; i < strlen(stl); i++)
        stri[i] = stl[i];
    for(i = 0; i < strlen(str); i++)
        stri[strlen(stl) + i] = str[i];
    stri[strlen(stl) + strlen(str) + 1] = '\0';
    char *sr = stri;
    //printf("sr: %ld %s\n", strlen(stri), sr);
    sr = reverseStr(sr);
    //printf("stri: %s\n", stri);

    //4.
    char srr[len * 2];

    memset(srr, 0, len);
    n = 0;
    int len_str = strlen(stri);
    //printf("%d\n", len_str);
    for(i = 0; i < len_str; i++)
    {
        flag = true;
        for(j = 0; j < n; j++)
        {
            if(srr[j] == stri[i])
                flag = false;
        }
        if(flag)
            srr[n++] = stri[i];
    }
    srr[len_str] = '\0';
    //printf("srr: %s\n", srr);
    char *sre = malloc(strlen(srr) * sizeof(char*));
    strcpy(sre, srr);
    sre = reverseStr(sre);
    //printf("%s\n", sre);


    return sre;
}
*/

/*
#define MAXSTACK 1000
char stack[MAXSTACK] = {'\0'};

int top = -1;
int isEmpty();
void push(char);
char pop();
char top_data();

int isEmpty(){
    if(top == -1){
        return 1;
    }else{
        return 0;
    }
}

void push(char data){
    stack[++top] = data;
}

char pop(){
    char data = stack[top];
    stack[top--] = '\0';
    return data;
}

char top_data(){
    return stack[top];
}

char* removeDuplicateLetters(char* s) {
    while(!isEmpty()){
        pop();
    }
    int count[26] = {0};
    int visited[26] = {0};
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == '\0'){
            break;
        }
        int num = 0;
        num = (int)s[i] - (int)'a';
        ++count[num];
    }
    // for(int j = 0; j <26; j++){
    //         printf("%c:", (char)((int)'a' + j));
    //         printf("%d", count[j]);
    //     }
    // printf("\n");
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == '\0'){
            break;
        }
        int num = 0;
        num = (int)s[i] - (int)'a';

        --count[num];
        if(visited[num] == 1){
            continue;
        }
        while(!isEmpty() && count[((int)top_data() - (int)'a')] > 0 && num < ((int)top_data() - (int)'a')){
            visited[((int)top_data() - (int)'a')] = 0;
            pop();
        }
        push(s[i]);
        visited[num] = 1;

        // for(int j = 0; j <26; j++){
        //     printf("%d", visited[j]);
        // }
        // printf("\n");
        // for(int j = 0; j <26; j++){
        //     printf("%d", count[j]);
        // }
        // printf("\n%s\n", stack);
    }

    return stack;
}
*/

// 4ms
char* removeDuplicateLetters(char *s)
{
    if(s == NULL)
        return NULL;

    //1. 用来统计字符串s中每个字符出现的次数
    int spaceLen = 26;
    int *count = (int *)malloc(spaceLen * sizeof(int));
    if(count == NULL)
        exit(EXIT_FAILURE);
    memset(count, 0, spaceLen * sizeof(int));//初始化为零

    int len = strlen(s);
    for(int i = 0; i < len; i++)
        count[s[i] - 'a']++;

    //2. 开辟一段空间来保存结果
    char *res = (char *)malloc(spaceLen * sizeof(char*));
    if(res == NULL)
        exit(EXIT_FAILURE);

    //3. 用来标识结果是否已经存在了该字符
    bool *isExistInRes = (bool *)malloc(spaceLen * sizeof(bool));
    if(isExistInRes == NULL)
        exit(EXIT_FAILURE);
    memset(isExistInRes, false, spaceLen * sizeof(bool));//注意：一定要初始化为false

    char ch;
    char sc;
    int i, end = -1;

    for(i = 0; i < len; i++)
    {
        ch = s[i];
        if(isExistInRes[ch - 'a'])
        {
            count[ch - 'a']--;
            continue;
        }
        //通过判断刚加入的这个元素是否应该加入，如果后面的元素小于刚刚加入的元素并且这个元素不是最后一次出现，则应该不加入
        while(end >= 0 && ((sc = res[end]) >= ch) && count[sc - 'a'] > 0)
        {
            end--;
            isExistInRes[sc - 'a'] = false;
        }
        res[++end] = ch;
        count[ch - 'a']--;
        isExistInRes[ch - 'a'] = true;
        printf("%c %d %s\n", ch, count[ch - 'a'], res);
    }
    res[++end] = '\0';

    return res;
}


// 8ms
/*
char* removeDuplicateLetters(char *s)
{
    int size = strlen(s), i, idx = 0;
    int last[128]; //a-z 26 is enough

    for(i = 0; i < size; i++)
    {
        last[s[i]] = i;
    }

    char *res = malloc(size* sizeof(char*));
    bool hava[128];
    memset(hava, 0, 128 * sizeof(bool));
    for(i = 0; i < size; i++)
    {
        char c = s[i];
        while(!hava[c] && idx > 0 && last[res[idx-1]] > i && c < res[idx-1])
        {
            hava[res[idx-1]] = false;
            idx--;
        }
        if(!hava[c])
        {
            hava[c] = true;
            res[idx++] = c;
        }
    }
    res[idx++] = '\0';
    return res;
}
*/

// 4ms
/*
char* removeDuplicateLetters(char* s)
{
    int len = strlen(s);
    if (len < 2)
        return s;

    int count[26] = {0}, choosen[26] = {0}, rlen = 0;

    for (int i = 0; i < len; i++)
    {
        count[s[i] - 'a']++;
        if (count[s[i] - 'a'] == 1)
            // get result string length
            rlen++;
    }

    char* result = (char*)malloc(sizeof(char) * (rlen + 1));

    for (int i = 0, j = 0; i < len; i++)
    {
        count[s[i] - 'a']--;
        if (choosen[s[i] - 'a'])
            continue;
        // while s[i] less than choosen char in result and has enough count
        // replace the choosen one
        while (j > 0 && s[i] < result[j - 1] && count[result[j - 1] - 'a'] > 0)
        {
            choosen[result[j - 1] - 'a'] = 0;
            j--;
        }
        // fill result string
        result[j++] = s[i];
        choosen[s[i] - 'a'] = 1;
    }
    result[rlen] = '\0';

    return result;
}
*/

int removeDuplicateLetters_main()
{
    char s[] = "dcbcabcd";//"mhdmsfxmcrslmaruresdouolyectxamdpsyadwxltpepthuwmuvacpvbtkvmdbqcmgavrrekczzltkkgutugzmmjncldgnkegchtuxrpzizhleefdgmigzznislffgzgtkbdabgyxojtkbqfjbkyrscnhizvibuivpsghrhhyarkvyvmexqhdcykulfsqalqwlubzupydxhvugizyhrozdlbdnyuxrersbuilyvouljenqdrxngeydzdltnacxydjflhmrbbujtqjlkfpydheitdeodtyugqljimnjtezgrqpfjyutqpzqiqjpehazybiodbybmvrjjhetdfahqbkucfmaabnpqcsqgdkhiosbndodnpjhanggnhdogfqskxdcjpltdsatdqwtpotgcfhketubhiakfijsxfmjcxnmmoqmdwmfypvarlpxhxkecuyytqjhmxtceopslowsbkreezeggfpmrfrluwtebuuigytcwjywkfcdqbxjdfgcetcxbudzhosjztrzjpqwthtzifbizhqsczetbxmiqaoshnqbybhcpmlyivgtafvoenxdverstplcovvixevpnfdmofdvpiecdzoiysbgdtfxtorlzbjltvdhjumpxovscmrlenfocwpkjmjclqrcyoudfmgxavhnewngsjqlkujwyyqhtxhdmlnvlrrdqzerxxvofnhdotmopxbedqrjzhbdxqsropfmqojqtwlxnkyrlslxcstyppchdpwelytfpfpdarzktxalyrogonlownmxkgxpdvttcmpcrrupiyynibzcxbbhmfunlqcshgyytxnkjadcyckekvcrehlmchgmqbofsodrznqwdbagmdwpnhmheplylucaprzqoyvihitivzgpjqclhwfynhvnnksxvfbqpqdstcghliaxhfmsnhyezwllyrydwfcokzmjuiwgophogqsrumbedwmeiyzwspssgsvwummjvbpulaqlocwyxjhzdijaakwwnrjijwylqgbguachbckkfocbvxaijyxpcrxtsjxknchwlzdouazckvicjetspprzopkfhrtyfyoscixyudpsxcdmaibcmpdprzslnupbrormpglmjgfwutxwacixjdesrewechbbrpreiyvowzixzdiwpfxqnbqobpjuawizuzljbkhgvvgbdoudyhmfzzccwqiyifyjzgcnuogaotnsxyukmhvlikcrqejuvtxwwvdajfamntywqyydevbglgsqfyvvjkxtkfsckelnsuzznmpryqhcacoqshcnskspbqapzljtzhwohqqrkdgcdidwetltjwafphryvnvxyvupmnxmngtecynhgtrweivdwjsfkfqetwxcijdxgebfborhsobkisvwsknxagarcjktkialbqpaostniygbvspdxbhruarkkjnettuvpfsidpjoxexqjlltstwgxffmrslwyipbanjutfqbahpdrtubmncjzpwlgzkhixxuwtzsexydwdeuggeddqsqsfztehjewenxvslbipiudbhhkflgjqygsthabxtocwtqbobvsrqzpeoaroeqgvwfojsxzhruqwwcssqgnwujiscnszlzoohfvglqrrewlvnlxhuubiwgdwrkzpolvwojvqohsyfhgrmhrzemsrvbwnwkywzqgkkxylanyhjtvxvhtrsscnpypmtnouprbtokjhvxgfddiigixwdbylvsofdrmelkrzujntmrjxwmluqmhinqpdihmlafqyhyxcjcsovrpjaovnclwkwkhrqnnotzmqralxfbwneqkwwshgvvurrmoyxbullwxivocehrdmpalzuthuwjqctcvihttnnktfhrgbwumjazfupbrztilnffbzheqeacgfcmmssusszmqiheinygltehwwsaxuvjgedutckpxuwtbovdjcdxxzvkcxvqjlthxreuhasfhcftfutbeelffzvhvcbtmvtvlimzchuyjbaukrictblxiuueuqcrmikeobsoxlhhkjlvamuhupfmuqguqlifjgwwyvqbftaafsgtcliiyniqjcqwzjhgynkzvwdjwquvpizixrhsufytzlqifuuzmnyunqzpjkawxrndzjedmgbgrazowphnyzhyouoywmvfxqsrhjygcwhvjkrlnyddklpblccgmbirdahrjwiyrhnfjpzlrravybzggklkoluiszjiznrpntndpvzqibtqzsaadpriizksjzevjcvxweurahisliczephpfjuuqgrdtalvliwzooqibplvaezhmqeakaasnamdditqrshmtxzvxdhjducjrgnrgjxfqyzwcgunzfyozoufithynydpbavlvovvfbvbkekzlibskkhjysyteyesvfzpztqbdqmefebulnhfufdiknruvjdfedaycumzditjeptpsgarhzynzxfttlujmltopejadhqyixoqumhxbdcaykhfngtdfmemaffrbroxpuezoyzkmqdyfvouywoqekpmllnkafeznzxhvhruzqomohrrloncoenurnxyzgzcronxhcupgsvogwuuxdaavvpcybkmatyabbtfszfvzldlzlekdcvvksugklzvsgqjdxcyvmnezsxrwfdgedhigfilkeiccsmhwqwhhspvbxpysksuwwkcjowhpecfqazdtqejqleezmuzlrfdsvpvncrxvtotiscpmsajnhfllbhfgdjgfjdihfuaymitdjejluccluzgbtcspagfcdcgwnhpzdyqaoqxpqytuxdhwgxwxziqecrkwqoofwanbkynizqambwzvmcjxvkeiqrjunmwwrwhelrocbtmadcceytohbjvxtovdtclilabmabqaolwhhgsraxorjohwxaldttbkswtaxlhpwxcncoxfotnmnkykahsijmuouvsjhtznerqbztftzppvptgfzhdteutcuchhhgkggwzqgdthzowcovxoemlhzaovgrcolakvioduybljadfawdprvuaewqqacbsvdrtvraqdqkrfvinclajunqlvkkpvxofhdqygbuukaplicqaiezdeolkzsnlwbpttvtrwsmiejzjjjfaeqkxgvhjagjnpuubnhgazhcsniznympivmspsiliqttprnyulpumkmvtcrccfqeqyhtjwfsbsitvhshgajibgvbkrphyxdjnhpewlvwnjokffvzkirqxhxjqglrvwjuihqjmncmefncpvrylippcrouprqzlwtctcphfuyilqbmjcemizbdcwqyskwcoexfbuyvtzviftgjlpkbivjrndtwvvocjplfbdtoobxeonzawymfctomlnsdikleqtozyhyftapkfpsqotmmitshrmldcdrupeadrkaroagwexxspekqdizgbzksakprgpderigvzvcgbfdjfyujeroubuuekivlnvoeplpgkwbmfuxweqbosqsqdfbthfqtvkplrvjphenmlbkcrephmtqfzlorcozieegnylznzjesnhpcmcgvzjqlikfukevbyydpxdkvcyxwysupnfnshvaqmhahevnexaxfyiatwrmodobzaemhfvcxbghdfhllpwpmcnoixqxrppbfnbraqitaxdgqtnsxtvqfduhclkrjzgbhbglicgdbmhirhgqvbnomybtembcryzuskxqudtbmvbeqyuutzgiqnntahihpoyfcahmucjlxofwjryjjfytgedaholssotycxhywdzyzdvlvbzxertxeipcklyjkrvcnnveqtudgkaewerdnrviabaamuyymumquprichjcctmervgmxrtuaxtxfvjpdcvwghnwkfbiqpivwvnleopvcncxxtatzbkfabmbgsosezazvxvevyjevuxhpyqncszmzlnlxbxfvrwkmmywuhqgceleiinnwrytshcigzelnrfpbadewyappzrjwzfqxiyjcbmzjvwzldbiicpwlnpvlgzfxtmvgxjdwjzifesaxozhnsubqtfaztagwbrjksnxdazxdpquwyklsogucuiixspqkpnipciomejhjgjoxgemkuijeawaqkwgmsmuvzbhkzbqoazxdglexgxbhveggxfzkxqsukvujamqsiwpdilqedzzgqcttkdabpmybkpyipuujpofqjpivzzautmvcfbyjzwyalxgxotsnazalicoxdzggxmafplrrrcecgfwkdkentjwjjiheutxfuxspdgvhcgyziobkwwndvhsvlfzlcjbicyxsdbhqigzewhixlxjqbknanywfyfduuvegiumtnpilzrerafyaylrpnjtsktbvavkdhxfzwirqawpzqbjopyfiukijyhtieevzldnxrkmtqedullaqorikoelfirmdkkxhfbkeiwpivooztijfmazvyumaqnfvcwwpmjnlfisvohttiqihwyknocbqloxokuwsrjhtoasiivununmefyrxaigcnagxareuciubdxatbmfieyboyrefthnhfyhufosfqdjeehgounlkgwpgluqthhnlypnxbexuqyhnaeppdfjgwpbibhjeeptwbzsvcebzwosynxkzfoaygrnnrgjdmfucnunkjnervmfwxskwibhlwdzzgppxhzdqsjnqrpxdlabbcdtxqpuptpmjtfovtmvgrxxremgbfzgcdcxuackddqgfkvzkwjxhtonbhujcrjpnqnswqswlkubxwyzpnculzjfvulqrnunvgotzkuyisjktxiwreftbalczvluoimahmsuupjmqrurrtttrdtivwkyxbypxqhlgnrvsortiqzirykcnpcjzasjcoxlwrpjpajfzbndlrbdrgcyydxdhtsjltqdfgbijxpepysmsyhblomaufoafcjabrdhtompxdjgssioytkedqoomktrfaxiarjrbjmnyezcwlfxqkrkazammudqhndfnkemdvjnbahkbmmpltzupwnybqdbrkmujsmoyttnhwhydgioatmygrosgsjmnawkxwchtpgcrkfrwvligaoowrrburrlzglozydsqnepqdvveagdjetzfcgupymxxbmfheydayaevamouyqlebnngackvtcpsuopuoawrkhwcnnqnstcrvcspqerredtahrkdnfdzapmyqzgplrepjsxznjsesiduxyslnlhlssszwtonxfmovkikbfopiyjmnfnztesldstolqyplczbpgrexwnfwzfdausdsyicchmfpebljwbvlqbrwdoeflmfvlgbxukuztxngftwjzvjntolpzcmflevmsnmlqmrxtdtwkmwtelrleeklaamfduqsdmhmvypaxzszcjytyurujeqriythhkoyurhrvbyqmozdnissivkwmiprrvieamftbjoicbjpvcphnnkmmjnrzqxclwrvnxjcohjhzwexgcjjrfyaisvvjccokxfycbaqwqgnylitmfyvdambrtbghcvbhbbvpeglhpvyawvxzphyjswgebbrpxyrnaczjmfyukvtdhtevbrisuoquynkrsysixsuktswwxynnmnnsqpgrappzlcnmflaubfkxowvzrwkxcjrseziwqvcdbfmcykajdephktudjosklyqpaqtbbnsdrvvbhjzbkybhryffalyczubankkrjbgtfkfvahdukeyybcxsfaudvgcchsraoxbqxbiemrudhjgfelwemkyeralmbgvtgqhvgpskmpvwaxsxqkksmbwrgisuydnyfmlucdfbujuqqyypcfotidqheyusosjfwcigdbppgrqwwveslwylqpaxfgjhmwxzodxjzjlwqtqonzggcjheevverggvtgejrlhwhatyydofnhmanobpntflkmrtnbsfxskzayrbrnbobxduitrlracnnaoqxebhogbrfbvebvvryopqlaeammwjhaiamqjoutptupvhctgemqizzxcficnognbilaawyldlmyrizaewcckefcehjrcpgiwuglwctywoofoaohlhlcqrynvmrybyblxftobasfskesimnyaqvlwmugaaupyclnwfieaampmfzhlgfivgoahejpacouzjhofcgczzaqhmszpmqpznfcuvbuvzhogbpgpmbaeljdgqjiulwrfokckeydozdvlpoaykdnbfjtgehnzjomelzrobfvzfmpfwuypazfgeteearekcczvrleoyrqudbiserphcrzyielrqewnlmgqldkzsdtrzwqolnttodzrbkwtzmlcrjiqttyftnhujnodccqndjefblvjwjqlarxcheacydskzhwbpzwqwkputfzusjgssstboytyhlbhrlmxctvsizbocnwuhrsccroujafkauxkrzlvsatrjhjoulhkxlxtwstdqrpibjwupkppkqmrnykoppecttmjxnstathqglcdpxhponvkzfnmhwvkugmtxecvcfqoyqlaclrdgdutsbladuggcpgkqrdawcqckuzrqfynrtewvqloyhmorpvchzntyhmjzlbfezeallvyoovzuvnlufswwdkslnyuecqmvzkiwqjmfkhvjnmvgzikahzocejltveeropdnazdpsicaihbntrqkbemhmuzeoqcwfiodvvutwwywluykmcnojwhhcwdscvkfxgwissbrazrrqfpshbjotiedrgdppdwtdcvwjhddogdzarvrztxyyqtnojothpjenfoesovqidpaiumrrkajhatfesxrdfshmufudlrtznfxcddhpfkkiawktxmbzctvbwpxbgiyslnlwjhayjlffmmbbonfhoqoutmjmxmqpuzkdefizbceaolibmchcadyqsxqgacebfjsswaaoenybknjpzhfumxestvpwtgswnysetqxupklnmpfnpnjryzdixolcisazlcvemwlyfrlmmhhzdkdpyvtuqquslvnhafjfkdiozuhmhocuhwivodtxlxuydzeyzzqegarbwvqiwpuvybzxyaalknyzxprrxmevzofurvqcbohpvjxtoemqevcynhftvhwmtwwtjalirukkhvxmhclontxpuafpwknwmwxdbashjtsznrkazngrmzbwoznypkdhalpvgrlflkejkbybjnemwzobzyfkysymmeubqzbgerkswxyojlrtyuzuwgydcdnroyokyhbpqesvtzabjgeabwwnlojsxieodeenonaqliptriswkdzcgfwjljeujdpmxsraizvdlvuqsmfwunkoafcjkemmlzbztfzmtdtvidjdvnxvwvvengcfajvtbsltpmisbhjyoraldphjxgmbyridhvltnqtutovnetksxagcbcsovypspzipjiidqqjyhqxptsloriuflxshqkssluvwyecchuqapazctewywnsjcalgmzxrcrycapnshukvvrrkhxcksbhfmubhdtuordlpsvvfduwbvrzswecwxrauqyvxlzcwgsucidisaglajsokzkhmzeheqvbkkxrzcphhzzahtqpchudofpsftgcjleprkzqcxqjuhmimgoelhyxvqwsopvmuothuviqymknnevoryficlkkifvoveagwwzxxsbtpmuphlzhybzavpmkagwtcktqkeovskupsuxsywxwncokqdhueaaqnoyjsxsizrepudbqyindauqecyymgjnpswktjauozkowpkjjcseezhasjsjpnsenkentcqgzclrmsgnuygjwqegglgcsufmicgwmlkbuxfqsogzfjiksjpdgrbjzprmwqkjojtwzkyuxwhhvrwmissqxsrhvyilasetwfitstpntcyrmaadhmuevzbbakftcqqbqkmuzlkqwrsisagkmjqswgsvnffjbgkvywioaabndgvwwnynxxnoikobyxvjcjuajwirdimyldarbosknvebwhfjuugntzwyqetffjlfcnffbuesymybtsxgiwpjayuznxwcgioajtqeorvzswicpfqhsntnhhvjrqcoqlzvdxydpkkchetlbwoexfpyjmokfnxzfiahakdsculjdxuwzkbftuimpxhnfawwgcffodpljgzhwyrybzkziwqhxbbkentxopopqetuhgkhbwwoixyyftsnfwcyecjoxbqjjaevbwhzibccbcldttaulcwwfztzehtutgfihwsgafjwmtevpyfvggmndmcsbnewpovordalmxklvzuelivmjagqqpzmczhefrhdyobvomkjhlpvlfljuorvwyvliahlbiazxwvnpjxombyuiqjsvdvvmrtjykyjrxtyabsjgpcoiodpzbdnrvczdazesbtrtrxqjsuwbetvapcujysdtiaeojoouhzxfhegsmvumtjpxqnvsaxcbzjdjjmzpdqnxczqszbtgubyvtydwytntwvskssqnggertcikdkpisgvekzushltzzfedcmtsthfvyucseiceqrajr";

    printf("\n%s\n", removeDuplicateLetters(s));

    return 0;
}