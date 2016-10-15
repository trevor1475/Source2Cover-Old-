#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string getGoal();
string getSkills( int n = 0 );
string getExperience( int n = 0 );
string getWord(ifstream &file, bool fix = false);
void   fixWord(string &word);

static string nextWord           = "";

static string jobTitle           = "No Title";
static string jobCity            = "No City";
static string jobProvince        = "No Province";
static string jobCountry         = "No Country";
static string jobOrganization    = "No Organization";

static string employerSalutation = "No Employer Salutation";
static string employerFirstName  = "No Employer First Name";
static string employerLastName   = "No Employer Last Name";
static string employerTitle      = "No Employer Title";
static string employerAddress    = "No Employer Address";
static string employerCity       = "No Employer City";
static string employerPostalCode = "No Employer Postal Code";
static string employerProvince   = "No Employer Country";

static int  languageCount  = 0;
static bool ada            = false;
static bool asmem          = false;
static bool bash           = false;
static bool c              = false;
static bool cpp            = false;
static bool cSharp         = false;
static bool cobol          = false;
static bool fortran        = false;
static bool gScript        = false;
static bool gTest          = false;
static bool html           = false;
static bool java           = false;
static bool perl           = false;
static bool php            = false;
static bool python         = false;
static bool sql            = false;
static bool oop            = false;
static bool objectiveC     = false;

static bool vmware         = false;
static bool qt             = false;
static bool gnu            = false;
static bool gdb            = false;
static bool valgrind       = false;
static bool git            = false;
static bool jenkins        = false;

static bool windows        = false;
static bool linux          = false;
static bool mac            = false;

static bool agile          = false;
static bool problemSolving = false;
static bool learning       = false;
static bool team           = false;
static bool bugs           = false;
static bool analysis       = false;
static bool fastPaced      = false;
static bool deadlines      = false;
static bool striving       = false;


int main ( int argc, char *argv[] )
{
    if ( argc != 3 )
    {
        cout << "Not enough arguments found. Enter <program name> <file of source> <term>" << endl;
        return 1;
    }

    ifstream infile( argv[1] );
    string term = argv[2];
    string temp = "";


    while ( infile.good( ) )
    {
        temp = getWord(infile);

        if ( temp.find( "Job" ) != string::npos )
        {
            temp = getWord(infile);

            if ( temp.find( "Title" ) != string::npos )
            {
                // Eat garbage
                while ( temp.find( "width=\"75%\">" ) == string::npos )
                {
                    temp = getWord(infile);
                }

                // jobTitle starts
                temp = getWord(infile);
                jobTitle = temp;
                temp = getWord(infile);
                while ( temp.find( "</td>" ) == string::npos )
                {
                    jobTitle += " " + temp;
                    temp = getWord(infile);
                }
            }
            else if ( temp.find( "City" ) != string::npos )
            {
                // Eat garbage
                while ( temp.find( "width=\"75%\">" ) == string::npos )
                {
                    temp = getWord(infile);
                }

                // jobCity starts
                temp = getWord(infile);
                jobCity = temp;
                temp = getWord(infile);
                while ( temp.find( "</td>" ) == string::npos )
                {
                    jobCity += " " + temp;
                    temp = getWord(infile);
                }
            }
            else if ( temp.find( "Province" ) != string::npos )
            {
                // Eat garbage
                while ( temp.find( "width=\"75%\">" ) == string::npos )
                {
                    temp = getWord(infile);
                }

                // jobProvince starts
                temp = getWord(infile);
                jobProvince = temp;
                temp = getWord(infile);
                while ( temp.find( "</td>" ) == string::npos )
                {
                    jobProvince += " " + temp;
                    temp = getWord(infile);
                }
            }
            else if ( temp.find( "Country" ) != string::npos )
            {
                // Eat garbage
                while ( temp.find( "width=\"75%\">" ) == string::npos )
                {
                    temp = getWord(infile);
                }

                // jobCountry starts
                temp = getWord(infile);
                jobCountry = temp;
                temp = getWord(infile);
                while ( temp.find( "</td>" ) == string::npos )
                {
                    jobCountry += " " + temp;
                    temp = getWord(infile);
                }
            }
            else if ( temp.find( "Contact" ) != string::npos )
            {
                temp = getWord(infile);

                if ( temp.find( "First" ) != string::npos )
                {
                    // Eat garbage
                    while ( temp.find( "width=\"75%\">" ) == string::npos )
                    {
                        temp = getWord(infile);
                    }

                    // employerFirstName starts
                    temp = getWord(infile);
                    employerFirstName = temp;
                    temp = getWord(infile);
                    while ( temp.find( "</td>" ) == string::npos )
                    {
                        employerFirstName += " " + temp;
                        temp = getWord(infile);
                    }
                }
                else if ( temp.find( "Last" ) != string::npos )
                {
                    // Eat garbage
                    while ( temp.find( "width=\"75%\">" ) == string::npos )
                    {
                        temp = getWord(infile);
                    }

                    // employerLastName starts
                    temp = getWord(infile);
                    employerLastName = temp;
                    temp = getWord(infile);
                    while ( temp.find( "</td>" ) == string::npos )
                    {
                        employerLastName += " " + temp;
                        temp = getWord(infile);
                    }
                }
            }
        }
        else if ( temp.find( "Organization" ) != string::npos )
        {
            // Eat garbage
            while ( temp.find( "width=\"75%\">" ) == string::npos )
            {
                temp = getWord(infile);
            }

            // jobOrganization starts
            temp = getWord(infile);
            jobOrganization = temp;
            temp = getWord(infile);
            while ( temp.find( "</td>" ) == string::npos )
            {
                jobOrganization += " " + temp;
                temp = getWord(infile);
            }
        }
        else if ( temp.find( "Salutation" ) != string::npos )
        {
            // Eat garbage
            while ( temp.find( "width=\"75%\">" ) == string::npos )
            {
                temp = getWord(infile);
            }

            // employerSalutation starts
            temp = getWord(infile);
            employerSalutation = temp;
            temp = getWord(infile);
            while ( temp.find( "</td>" ) == string::npos )
            {
                employerSalutation += " " + temp;
                temp = getWord(infile);
            }
        }
        else if ( temp.find( "Title" ) != string::npos )
        {
            // Eat garbage
            while ( temp.find( "width=\"75%\">" ) == string::npos )
            {
                temp = getWord(infile);
            }

            // employerTitle starts
            temp = getWord(infile);
            employerTitle = temp;
            temp = getWord(infile);
            while ( temp.find( "</td>" ) == string::npos )
            {
                employerTitle += " " + temp;
                temp = getWord(infile);
            }
        }
        else if ( temp.find( "Address" ) != string::npos )
        {
            temp = getWord(infile); // eat garbage

            temp = getWord(infile); // Line #
            if ( temp.find( "One" ) != string::npos )
            {
                // Eat garbage
                while ( temp.find( "width=\"75%\">" ) == string::npos )
                {
                    temp = getWord(infile);
                }

                // employerAddress starts
                temp = getWord(infile);
                employerAddress = temp;
                temp = getWord(infile);
                while ( temp.find( "</td>" ) == string::npos )
                {
                    employerAddress += " " + temp;
                    temp = getWord(infile);
                }
            }
        }
        else if ( temp.find( "City" ) != string::npos )
        {
            // Eat garbage
            while ( temp.find( "width=\"75%\">" ) == string::npos )
            {
                temp = getWord(infile);
            }

            // employerCity starts
            temp = getWord(infile);
            employerCity = temp;
            temp = getWord(infile);
            while ( temp.find( "</td>" ) == string::npos )
            {
                employerCity += " " + temp;
                temp = getWord(infile);
            }
        }
        else if ( temp.find( "Postal" ) != string::npos )
        {
            // Eat garbage
            while ( temp.find( "width=\"75%\">" ) == string::npos )
            {
                temp = getWord(infile);
            }

            // employerPostalCode starts
            temp = getWord(infile);
            employerPostalCode = temp;
            temp = getWord(infile);
            while ( temp.find( "</td>" ) == string::npos )
            {
                employerPostalCode += " " + temp;
                temp = getWord(infile);
            }
        }
        else if ( temp.find( "Province" ) != string::npos )
        {
            // Eat garbage
            while ( temp.find( "width=\"75%\">" ) == string::npos )
            {
                temp = getWord(infile);
            }

            // employerProvince starts
            temp = getWord(infile);
            employerProvince = temp;
            temp = getWord(infile);
            while ( temp.find( "</td>" ) == string::npos )
            {
                employerProvince += " " + temp;
                temp = getWord(infile);
            }
        }
        else
        {
            fixWord(temp);

            if ( temp.compare( "ADA" ) == 0 || temp.compare( "Ada" ) == 0 || temp.compare( "ada" ) == 0  )
            {
                ada = true;
            }
            else if ( temp.compare( "ASM" ) == 0 || temp.compare( "Asm" ) == 0 || temp.compare( "asm" ) == 0 || temp.compare( "Asmembly" ) == 0 || temp.compare( "asmembly" ) == 0 )
            {
                asmem = true;
            }
            else if ( temp.compare( "Bash" ) == 0 || temp.compare( "bash" ) == 0 )
            {
                bash = true;
            }
            else if ( temp.compare( "Python" ) == 0 || temp.compare( "python" ) == 0 )
            {
                python = true;
            }
            else if ( temp.compare( "Shell" ) == 0 || temp.compare( "shell" ) == 0 || temp.compare( "Scripting" ) == 0 || temp.compare( "scripting" ) == 0 )
            {
                bash = true;
                python = true;
            }
            else if ( temp.compare( "objective" ) == 0 )
            {
                temp = getWord(infile, true);

                if ( temp.compare( "c" ) == 0 )
                {
                    objectiveC = true;
                }
            }
            else if ( temp.compare( "C" ) == 0 || temp.compare( "c" ) == 0 )
            {
                c = true;
            }
            else if ( temp.compare( "C#" ) == 0 || temp.compare( "c#" ) == 0 )
            {
                cSharp = true;
            }
            else if ( temp.compare( "C++" ) == 0 || temp.compare( "c++" ) == 0 )
            {
                cpp = true;
            }
            else if ( temp.compare( "oop" ) == 0 )
            {
                oop = true;
            }
            else if ( temp.compare( "Object" ) == 0 || temp.compare( "object" ) == 0 )
            {
                temp = getWord(infile, true);

                if ( temp.compare( "Oriented" ) == 0 || temp.compare( "oriented" ) == 0 )
                {
                    oop = true;
                }
            }
            else if ( temp.compare( "COBOL" ) == 0 || temp.compare( "Cobol" ) == 0 || temp.compare( "cobol" ) == 0 )
            {
                cobol = true;
            }
            else if ( temp.compare( "FORTRAN" ) == 0 || temp.compare( "Fortran" ) == 0 || temp.compare( "fortran" ) == 0 )
            {
                fortran = true;
            }
            else if ( temp.compare( "Google" ) == 0 || temp.compare( "google" ) == 0 )
            {
                temp = getWord(infile, true);
                if ( temp.find( "Test" ) != string::npos || temp.find( "test" ) != string::npos )
                {
                    gTest = true;
                }
                else if ( temp.find( "Script" ) != string::npos || temp.find( "script" ) != string::npos )
                {
                    gScript = true;
                }
            }
            else if ( temp.compare( "test" ) == 0 )
            {
                temp = getWord(infile, true);
                if ( temp.find( "use" ) != string::npos )
                {
                    temp = getWord(infile, true);
                }

                if ( temp.find( "case" ) != string::npos || temp.find( "cases" ) != string::npos )
                {
                    gTest = true;
                }

                if ( temp.find( "automation" ) != string::npos )
                {
                    jenkins = true;
                }
            }
            else if ( temp.compare( "automatic" ) == 0 )
            {
                temp = getWord(infile, true);
                if ( temp.find( "test" ) != string::npos )
                {
                    jenkins = true;
                }
            }
            else if ( temp.compare( "unit" ) == 0 )
            {
                temp = getWord(infile, true);
                if ( temp.find( "test" ) != string::npos )
                {
                    gTest = true;
                }
            }
            else if ( temp.compare( "HTML" ) == 0 || temp.compare( "Html" ) == 0 || temp.compare( "html" ) == 0 )
            {
                html = true;
            }
            else if ( temp.compare( "JAVA" ) == 0 || temp.compare( "Java" ) == 0 || temp.compare( "java" ) == 0 )
            {
                java = true;
            }
            else if ( temp.compare( "PERL" ) == 0 || temp.compare( "perl" ) == 0 || temp.compare( "perl" ) == 0 )
            {
                perl = true;
            }
            else if ( temp.compare( "PHP" ) == 0 || temp.compare( "Php" ) == 0 || temp.compare( "php" ) == 0 )
            {
                php = true;
            }
            else if ( temp.compare( "Python" ) == 0 || temp.compare( "python" ) == 0 )
            {
                python = true;
            }
            else if ( temp.compare( "SQL" ) == 0 || temp.compare( "Sql" ) == 0 || temp.compare( "sql" ) == 0 )
            {
                sql = true;
            }
            else if ( temp.compare( "VMware" ) == 0 || temp.compare( "VMWare" ) == 0 || temp.compare( "vmware" ) == 0 )
            {
                vmware = true;
            }
            else if ( temp.compare( "QT" ) == 0 || temp.compare( "Qt" ) == 0 || temp.compare( "qt" ) == 0 )
            {
                qt = true;
            }
            else if ( temp.compare( "GNU" ) == 0 || temp.compare( "Gnu" ) == 0 || temp.compare( "gnu" ) == 0 )
            {
                gnu = true;
            }
            else if ( temp.compare( "Valgrind" ) == 0 || temp.compare( "valgrind" ) == 0 )
            {
                valgrind = true;
            }
            else if ( temp.compare( "GDB" ) == 0 || temp.compare( "Gdb" ) == 0 || temp.compare( "gdb" ) == 0 )
            {
                gdb = true;
            }
            else if ( temp.compare( "debug" ) == 0 || temp.compare( "debugging" ) == 0 || temp.compare( "bugs" ) == 0 )
            {
                valgrind = true;
                gdb = true;
            }
            else if ( temp.compare("git") == 0 )
            {
                git = true;
            }
            else if ( temp.compare( "Agile" ) == 0 || temp.compare( "agile" ) == 0 )
            {
                agile = true;
            }
            else if ( temp.compare( "solving" ) == 0 || temp.compare( "Problem" ) == 0 || temp.compare( "problem" ) == 0 || temp.compare( "Solutions" ) == 0 || temp.compare( "solutions" ) == 0 
                  || temp.compare( "Solving" ) == 0 || temp.compare( "solutiion" ) == 0 || temp.compare( "Solution" ) == 0 )
            {
                problemSolving = true;
            }
            else if ( temp.compare( "Learn" ) == 0 || temp.compare( "learn" ) == 0 || temp.compare( "Learning" ) == 0 || temp.compare( "learning" ) == 0  || temp.compare( "Develop" ) == 0
                  || temp.compare( "develop" ) == 0 || temp.compare( "Developing" ) == 0 || temp.compare( "developing" ) == 0 || temp.compare( "Development" ) == 0 || temp.compare( "development" ) == 0 )
            {
                learning = true;
            }
            else if ( temp.compare( "Group" ) == 0 || temp.compare( "group" ) == 0 || temp.compare( "Team" ) == 0 || temp.compare( "team" ) == 0 )
            {
                team = true;
            }
            else if ( temp.compare( "Bugs" ) == 0 || temp.compare( "bugs" ) == 0 || temp.compare( "Fix" ) == 0 || temp.compare( "fix" ) == 0 )
            {
                bugs = true;
            }
            else if ( temp.compare( "Analysis" ) == 0 || temp.compare( "analysis" ) == 0 || temp.compare( "Analytical" ) == 0 || temp.compare( "analytical" ) == 0 )
            {
                analysis = true;
            }
            else if ( temp.compare( "fast" ) == 0 || temp.compare( "Fast" ) == 0 )
            {
                temp = getWord(infile, true);

                if ( temp.compare( "Paced" ) == 0 || temp.compare( "paced" ) == 0 )
                {
                    fastPaced = true;
                }
            }
            else if ( temp.compare( "fast-paced" ) == 0 || temp.compare( "Fast-paced" ) == 0 )
            {
                fastPaced = true;
            }
            else if ( temp.compare( "Due" ) == 0 || temp.compare( "due" ) == 0 )
            {
                temp = getWord(infile, true);

                if ( temp.compare( "Dates" ) == 0 || temp.compare( "dates" ) == 0 || temp.compare( "Date" ) == 0 || temp.compare( "date" ) == 0 )
                {
                    deadlines = true;
                }
            }
            else if ( temp.compare( "Deadlines" ) == 0 || temp.compare( "deadlines" ) == 0 )
            {
                deadlines = true;
            }
            else if ( temp.compare( "Strives" ) == 0 || temp.compare( "strives" ) == 0 || temp.compare( "Striving" ) == 0 || temp.compare( "striving" ) == 0 )
            {
                striving = true;
            }
        }
    }



    infile.close( );





    cout <<                                           "TREVOR LIVINGSTON"                                                                                                           << endl;
    cout <<                                         "32-745 Farmstead Drive"                                                                                                        << endl;
    cout <<                                              "Milton, ON"                                                                                                               << endl;
    cout <<                                             "905-876-5630"                                                                                                              << endl;
    cout <<                                          "livingston-t@live.ca"                                                                                                     << endl;
    cout << employerSalutation << " " << employerFirstName << " " << employerLastName                                                                                               << endl;
    cout << employerTitle                                                                                                                                                           << endl;
    cout << jobOrganization                                                                                                                                                         << endl;
    cout << employerAddress                                                                                                                                                         << endl;
    cout << employerCity << ", " << employerProvince                                                                                                                                << endl;
    cout <<                                                                                                                                                                            endl;
    cout << "Dear " << employerSalutation << " " << employerLastName << ","                                                                                                         << endl;
    cout << "\tI am extremely interested in the position of " << jobTitle << ".";
    cout << " I am starting my third year as a software engineering co-op student and available for a 4 month work term for the " << term << ". ";
    cout << getGoal( );
    cout << getSkills( )                                                                                                                                                            << endl;
    cout <<                                                                                                                                                                            endl;
    cout << "\t" << getExperience( )                                                                                                                                                << endl;
    cout <<                                                                                                                                                                            endl;
    cout << "\tI am extremely interested in working with " << jobOrganization << ". ";
    cout << "I believe I can be a strong asset to you and your company. ";
    cout << "I look forward to demonstrating my skills further and meeting you and the " << jobOrganization << " development team. ";
    cout << "Thank you for your consideration, and I look forward to hearing from you."                                                                                             << endl;
    cout <<                                                                                                                                                                            endl;
    cout << "Sincerely,"                                                                                                                                                            << endl;
    cout << "Trevor Livingston"                                                                                                                                                     << endl;


    
    return 0;
}

string getGoal( )
{
    if ( team )
    {
        team = false;
        return "This opportunity is very appealing as my goal is to work in a team of developers with the aim to create an excellent user experience during my co-op work terms. ";
    }
    else if ( agile )
    {
        agile = false;
        return "This opportunity is very appealing as my goal is to work in an agile environment with the aim to create an excellent user experience during my co-op work terms. ";
    }


    return "This opportunity is very appealing as my goal is to work in an environment where I can fully utilize and further develop my skills. ";
}

string getSkills( int n )
{
    string intro = "";

    if ( n == 0 )
    {
        intro += "I believe, in this position I would be of great benefit with my set of skills combined with my ";
    }
    else if ( n == 1 )
    {
        intro += ", as well as my ";
    }
    else if ( n == 2 )
    {
        return ". ";
    }

    if ( analysis || problemSolving || bugs )
    {
        analysis = false;
        problemSolving = false;
        bugs = false;
        return intro + "analytical and problem-solving abilities" + getSkills( n + 1 );
    }
    else if ( learning || striving )
    {
        learning = false;
        striving = false;
        return intro + "ability to learn and adapt to new technology quickly" + getSkills( n + 1 );
    }
    else if ( fastPaced || deadlines )
    {
        fastPaced = false;
        deadlines = false;
        return intro + "work calmly and efficiently under a tight schedule to ensure deadlines are met" + getSkills( n + 1 );
    }

    return intro + "**** INSUFFICIENT SKILLS FOUND ****"; 
}

string getExperience( int n )
{
    string intro = "";

    if ( n == 0 )
    {
        intro += "";
    }
    else if ( n == 1 )
    {
        intro += "Also, ";
    }
    else if ( n == 2 )
    {
        intro += "Furthermore, ";
    }
    else if ( n == 3 )
    {
        intro += "Finally, ";
    }
    else if ( n == 4 )
    {
        return "";
    }

    if ( cpp || qt || oop )
    {
        cpp = false;
        qt = false;
        oop = false;
        return intro + "I have experience with C++ from my previous work term. Which ranged from gui enhancements using Qt as a framework to bit reading from a hardware connection. "
                     + getExperience( n + 1 );
    }
    else if ( c )
    {
        c = false;
        if ( n == 0 )
        {
            intro += "My";
        }
        else
        {
            intro += "my";
        }
        return intro + " natural language is C. I have grown my foundation throughout my education with C as the primary language that I used. I have a lot of experience and feel most confident in utilizing. "
                     + getExperience( n + 1 );
    }
    else if ( gnu )
    {
        gnu = false;
        if ( git )
        {
            git = false;
            return intro + "I frequently use the GNU project as well as git for convience and to backup almost every project that I program. " + getExperience( n + 1 );
        }
        return intro + "I frequently use the GNU project, as it is an exellent source to get Linux features onto my Windows. " + getExperience( n + 1 );
    }
    else if ( agile )
    {
        agile = false;
        return intro + "I have been learning about agile ideology in my courses, and recently got the chance to live it at my last co-op. " + getExperience( n + 1 );
    }
    else if ( git )
    {
        git = false;
        return intro + "I frequently use git, for convenience and to backup almost every project that I program. " + getExperience( n + 1 );
    }
    else if ( valgrind || gdb )
    {
        valgrind = false;
        gdb = false;
        return intro + "my main debugging tools are Valgrind and gdb. I always do a quick memory test whether I run into problems or not with Valgrind, and use gdb if I need to trace into the program to solve problems that Valgrind may miss. "
                     + getExperience( n + 1 );
    }
    else if ( bash || python )
    {
        bash = false;
        python = false;
        return intro + "I have done shell scripting through bash and python for simple installation of projects that allow users to build and install the project with ease. " + getExperience( n + 1 );
    }
    else if ( gTest || jenkins )
    {
        gTest = false;
        jenkins = false;
        return intro + "I experienced in automation testing through utilizing Google Tests and Jenkins. " + getExperience( n + 1 );
    }
    else
    {
        if(n < 3)
        {
            return "**** INSUFFICIENT EXPERIENCE FOUND ****";
        }
        return intro + "as a Software Engineer, I have been taught the best practices for design of applications and their documentation. I have knowledge and understanding of the need to design various prototypes for an application, and the idioms and patterns that would be involved.";
    }
}


string getWord( ifstream &infile, bool fixWordAsWell )
{
    string temp = "";

    if ( nextWord.compare("") == 0 )
    {
        infile >> temp;
    }
    else
    {
        temp = nextWord;
        nextWord = "";
    }

    if ( fixWordAsWell )
    {
        fixWord(temp);
    }

    return temp;
}

void fixWord(string &temp)
{
    for ( int i = 0; i < temp.length(); i++ )
    {
        if ( temp.at(i) >= 65 && temp.at(i) <= 90 )
        {
            temp.at(i) += 32;
        }
        else if ( temp.at(i) == 45 )
        {
            temp.erase( temp.begin() + i, temp.end() );
        }
        else if ( temp.at(i) == 44 || temp.at(i) == 47 || temp.at(i) == 60 || temp.at(i) == 62 )
        {
            nextWord = temp.substr( i + 1 );
            temp.erase( i );
        }
        else if ( temp.at(i) != 35 && temp.at(i) != 43 && (temp.at(i) < 48 || (temp.at(i) > 57 && temp.at(i) < 97) || temp.at(i) > 122) )
        {
            temp.erase( temp.begin() + i );
            i--;
        }
    }
}