// learn.cpp
// Interactive C++ Learning Tool (English & Arabic)
// Terminal-based, single file, progressive lessons by level
// Author: AI Assistant
// C++11 or newer required
//
// Usage: Compile and run in terminal
// g++ -std=c++11 learn.cpp -o learn && ./learn

#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <codecvt>
#include <fstream>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <filesystem>
#include <iomanip>
#include <thread>
#include <chrono>

// --- Localization Structures ---
struct Lesson {
    std::string explanation;
    std::string code;
    std::string challenge;
    std::string solution;
    std::string expected_output;
    std::string hint;
    std::string related_title;
    std::string related_level;
};

struct Level {
    std::string name;
    std::vector<Lesson> lessons;
};

struct Localization {
    // UI Strings
    std::string select_language;
    std::string select_level;
    std::string beginner;
    std::string intermediate;
    std::string advanced;
    std::string prompt_command;
    std::string invalid_command;
    std::string lesson_header;
    std::string code_header;
    std::string challenge_header;
    std::string solution_header;
    std::string goodbye;
    std::string commands_hint;
    std::string back_first;
    std::string next_last;
    // New UI strings for features
    std::string related_topic;
    std::string note_prompt;
    std::string note_saved;
    std::string notes_header;
    std::string no_notes;
    std::string reminder_message;
    std::string instructor_mode;
    std::string instructor_password;
    std::string bookmark_saved;
    std::string bookmark_loaded;
    std::string weekly_stats;
    std::string backup_created;
    // Welcome message for typing animation
    std::string welcome_message;
    std::vector<Level> levels;
};

// --- English Content ---
Localization en = {
    // UI Strings
    "Select language / اختر اللغة:\n1) English\n2) العربية",
    "Select your current level:\n1) Beginner 👶\n2) Intermediate 🧑‍💻\n3) Advanced 👨‍🏫",
    "Beginner",
    "Intermediate",
    "Advanced",
    "Type a command (next, back, repeat, code, solution, exit, note, notes, bookmark, goto, mode): ",
    "Invalid command. Please try again.",
    "\n--- Lesson ",
    "\nSample Code:",
    "\nMini Challenge:",
    "\nSolution:",
    "Goodbye! Happy learning!",
    "[Commands: next, back, repeat, code, solution, exit, note, notes, bookmark, goto, mode]",
    "You are at the first lesson.",
    "You are at the last lesson.",
    // New UI strings for features
    "💡 Related Topic: ",
    "Enter your note for this lesson: ",
    "✅ Note saved successfully!",
    "\n📝 Your Notes:",
    "No notes found.",
    "⏰ It's been {days} days since your last session. Ready to continue?",
    "👨‍🏫 Instructor Mode",
    "Enter instructor password: ",
    "🔖 Bookmark saved at lesson ",
    "🔖 Jumped to bookmarked lesson ",
    "📊 Weekly Statistics Summary",
    "🔁 Progress backup created successfully!",
    // Welcome message for typing animation
    "Hello! I'm your personal programming instructor.\nI'll guide you in learning C++ in your favorite language!\nCreated with care by your developer, Othman Mohamed. Let's get started! 💻🚀",
    // Levels & Lessons
    {
        { // Beginner
            "Beginner 👶",
            {
                {"What is programming?\nProgramming is giving instructions to a computer to perform tasks.", "// No code for this concept.", "What is programming in your own words?", "Programming is telling a computer what to do using code.", "Programming is telling a computer what to do using code.", "A program is a set of instructions that tells the computer what to do."},
                {"What is C++?\nC++ is a powerful programming language used for building software, games, and more.", "// No code for this concept.", "Name one thing you can build with C++.", "Games, applications, operating systems, etc.", "Games, applications, operating systems, etc.", "You can build games, applications, and operating systems."},
                {"Hello World!\nThe first program in any language prints a message.", "#include <iostream>\nint main() {\n    std::cout << \"Hello, World!\\n\";\n    return 0;\n}", "What does this program print?", "Hello, World!", "Hello, World!", "Look at the string inside cout."},
                {"Input and Output\nYou can read and print values using std::cin and std::cout.", "#include <iostream>\nint main() {\n    int age;\n    std::cout << \"Enter your age: \";\n    std::cin >> age;\n    std::cout << \"You are \" << age << \" years old.\\n\";\n    return 0;\n}", "How do you print a value in C++?", "Using std::cout.", "Using std::cout.", "Remember to include iostream for cin and cout."},
                {"Variables and Types\nVariables store data. C++ has types like int, double, char.", "int x = 5;\ndouble y = 3.14;\nchar c = 'A';", "What type would you use for a decimal number?", "double", "double", "Use double for decimal numbers."},
                {"If/Else\nUse if/else to make decisions.", "int x = 10;\nif (x > 5) {\n    std::cout << \"x is greater than 5\\n\";\n} else {\n    std::cout << \"x is 5 or less\\n\";\n}", "What does this code print if x = 3?", "x is 5 or less", "x is 5 or less", "Remember to use double quotes for strings."}
            }
        },
        { // Intermediate
            "Intermediate 🧑‍💻",
            {
                {"Loops\nLoops repeat actions. For example, a for loop.", "for (int i = 0; i < 5; ++i) { std::cout << i << \" \"; }", "How many times does this loop run?", "5 times (i = 0 to 4)", "5 times (i = 0 to 4)", "The loop will run from i=0 to i=4."},
                {"Functions\nFunctions group code to perform tasks.", "int add(int a, int b) {\n    return a + b;\n}\n// Usage:\nint sum = add(2, 3);", "What does add(2, 3) return?", "5", "5", "Remember to return the value from the function.", "Classes & OOP", "Advanced 👨‍🏫"},
                {"Arrays\nArrays store multiple values of the same type.", "int arr[3] = {1, 2, 3};\nstd::cout << arr[1]; // prints 2", "What does arr[2] equal?", "3", "3", "Arrays are 0-indexed."},
                {"Switch\nSwitch selects code to run based on a value.", "int day = 2;\nswitch(day) {\n    case 1: std::cout << \"Mon\"; break;\n    case 2: std::cout << \"Tue\"; break;\n    default: std::cout << \"Other\";\n}", "What does this print if day = 2?", "Tue", "Tue", "Remember to use break to exit the case."},
                {"Error Handling Basics\nUse try/catch to handle errors.", "try {\n    throw std::runtime_error(\"Error!\");\n} catch (const std::exception& e) {\n    std::cout << e.what();\n}", "What does e.what() print?", "Error!", "Error!", "Remember to include iostream for cin and cout."}
            }
        },
        { // Advanced
            "Advanced 👨‍🏫",
            {
                {"Classes & OOP\nClasses group data and functions.", "class Person {\npublic:\n    std::string name;\n    void say_hello() {\n        std::cout << \"Hello, I am \" << name << std::endl;\n    }\n};", "How do you call say_hello on a Person p?", "p.say_hello();", "p.say_hello();", "Remember to use std::endl for a newline."},
                {"Pointers & Memory\nPointers store addresses of variables.", "int x = 10;\nint* p = &x;\nstd::cout << *p; // prints 10", "What does *p print?", "10", "10", "Remember to use *p to access the value at the address."},
                {"File Handling\nRead/write files using fstream.", "#include <fstream>\nstd::ofstream out(\"file.txt\");\nout << \"Hello\";\nout.close();", "Which header is needed for file streams?", "<fstream>", "<fstream>", "Remember to include fstream for file operations."},
                {"STL\nThe Standard Template Library provides useful containers.", "#include <vector>\nstd::vector<int> v = {1,2,3};\nv.push_back(4);", "How do you add an element to a vector?", "v.push_back(value);", "v.push_back(value);", "Remember to use v.push_back() to add elements."},
                {"Mini Project\nCombine what you learned!\nWrite a program that asks for 3 numbers and prints their sum.", "#include <iostream>\nint main() {\n    int a, b, c;\n    std::cin >> a >> b >> c;\n    std::cout << (a + b + c);\n    return 0;\n}", "What does this program do?", "Reads 3 numbers and prints their sum.", "Reads 3 numbers and prints their sum.", "Remember to use cin for input and cout for output."}
            }
        }
    }
};

// --- Arabic Content ---
Localization ar = {
    // UI Strings
    "اختر اللغة / Select language:\n1) English\n2) العربية",
    "اختر مستواك الحالي:\n1) مبتدئ 👶\n2) متوسط 🧑‍💻\n3) متقدم 👨‍🏫",
    "مبتدئ",
    "متوسط",
    "متقدم",
    "اكتب أمر (التالي، السابق، إعادة، الكود، الحل، خروج، ملاحظة، ملاحظات، علامة، اذهب، وضع): ",
    "أمر غير صالح. حاول مرة أخرى.",
    "\n--- الدرس ",
    "\nمثال الكود:",
    "\nتحدي صغير:",
    "\nالحل:",
    "وداعاً! تعلم سعيد!",
    "[الأوامر: التالي، السابق، إعادة، الكود، الحل، خروج، ملاحظة، ملاحظات، علامة، اذهب، وضع]",
    "أنت في أول درس.",
    "أنت في آخر درس.",
    // New UI strings for features
    "💡 موضوع ذو صلة: ",
    "أدخل ملاحظتك لهذا الدرس: ",
    "✅ تم حفظ الملاحظة بنجاح!",
    "\n📝 ملاحظاتك:",
    "لا توجد ملاحظات.",
    "⏰ مر {days} أيام منذ جلستك الأخيرة. مستعد للمتابعة؟",
    "👨‍🏫 وضع المحاضر",
    "أدخل كلمة مرور المحاضر: ",
    "🔖 تم حفظ العلامة في الدرس ",
    "🔖 انتقل إلى الدرس المحدد ",
    "📊 ملخص الإحصائيات الأسبوعية",
    "🔁 تم إنشاء نسخة احتياطية بنجاح!",
    // Welcome message for typing animation
    "أهلاً! أنا أستاذك الخاص في تعلم البرمجة.\nسأرشدك في تعلم ++C بلغتك المفضلة!\nتم تطويري بحب بواسطة مطورك عثمان محمد. هيا نبدأ! 💻🚀",
    // Levels & Lessons
    {
        { // Beginner
            "مبتدئ 👶",
            {
                {"ما البرمجة؟\nالبرمجة هي إعطاء أوامر للحاسوب لتنفيذ مهام.", "// لا يوجد كود لهذا المفهوم.", "ما هي البرمجة بكلماتك؟", "البرمجة هي إخبار الحاسوب بما يجب فعله باستخدام الكود.", "البرمجة هي إخبار الحاسوب بما يجب فعله باستخدام الكود.", "البرمجة هي إخبار الحاسوب بما يجب فعله باستخدام الكود."},
                {"ما هي ++C؟\n++C لغة برمجة قوية لبناء البرامج والألعاب والمزيد.", "// لا يوجد كود لهذا المفهوم.", "اذكر شيئاً يمكن بناؤه بـ ++C.", "ألعاب، تطبيقات، أنظمة تشغيل، إلخ.", "ألعاب، تطبيقات، أنظمة تشغيل، إلخ.", "يمكنك بناء ألعاب، تطبيقات، أنظمة تشغيل."},
                {"برنامج Hello World!\nأول برنامج يطبع رسالة.", "#include <iostream>\nint main() {\n    std::cout << \"Hello, World!\\n\";\n    return 0;\n}", "ماذا يطبع هذا البرنامج؟", "Hello, World!", "Hello, World!", "تأكد من أنك قمت بطباعة الرسالة باستخدام std::cout."},
                {"الإدخال والإخراج\nيمكنك قراءة وطباعة القيم باستخدام std::cin و std::cout.", "#include <iostream>\nint main() {\n    int age;\n    std::cout << \"أدخل عمرك: \";\n    std::cin >> age;\n    std::cout << \"عمرك \" << age << \" سنة.\\n\";\n    return 0;\n}", "كيف تطبع قيمة في ++C؟", "باستخدام std::cout.", "باستخدام std::cout.", "تأكد من أنك قمت بطباعة القيمة باستخدام std::cout."},
                {"المتغيرات والأنواع\nالمتغيرات تخزن البيانات. ++C بها أنواع مثل int, double, char.", "int x = 5;\ndouble y = 3.14;\nchar c = 'A';", "أي نوع تستخدمه للعدد العشري؟", "double", "double", "استخدم double للأرقام العشرية."},
                {"if/else\nاستخدم if/else لاتخاذ قرارات.", "int x = 10;\nif (x > 5) {\n    std::cout << \"x أكبر من 5\\n\";\n} else {\n    std::cout << \"x أقل أو يساوي 5\\n\";\n}", "ماذا يطبع الكود إذا كان x = 3؟", "x أقل أو يساوي 5", "x أقل أو يساوي 5", "تأكد من أنك قمت بطباعة الرسالة باستخدام std::cout."}
            }
        },
        { // Intermediate
            "متوسط 🧑‍💻",
            {
                {"الحلقات\nالحلقات تكرر الأوامر. مثال: حلقة for.", "for (int i = 0; i < 5; ++i) { std::cout << i << \" \"; }", "كم مرة تعمل هذه الحلقة؟", "5 مرات (i = 0 إلى 4)", "5 مرات (i = 0 إلى 4)", "تأكد من أنك قمت بطباعة الرقم باستخدام std::cout."},
                {"الدوال\nالدوال تجمع كوداً لتنفيذ مهمة.", "int add(int a, int b) {\n    return a + b;\n}\n// الاستخدام:\nint sum = add(2, 3);", "ماذا تعيد add(2, 3)؟", "5", "5", "تأكد من أنك قمت بإرجاع القيمة باستخدام return.", "الكائنات والبرمجة الكائنية", "متقدم 👨‍🏫"},
                {"المصفوفات\nالمصفوفة تخزن عدة قيم من نفس النوع.", "int arr[3] = {1, 2, 3};\nstd::cout << arr[1]; // يطبع 2", "كم تساوي arr[2]؟", "3", "3", "تأكد من أنك قمت بطباعة القيمة باستخدام std::cout."},
                {"switch\nتحدد الكود الذي ينفذ حسب القيمة.", "int day = 2;\nswitch(day) {\n    case 1: std::cout << \"الاثنين\"; break;\n    case 2: std::cout << \"الثلاثاء\"; break;\n    default: std::cout << \"أخرى\";\n}", "ماذا يطبع إذا كان day = 2؟", "الثلاثاء", "الثلاثاء", "تأكد من أنك قمت بطباعة الرسالة باستخدام std::cout."},
                {"أساسيات معالجة الأخطاء\nاستخدم try/catch لمعالجة الأخطاء.", "try {\n    throw std::runtime_error(\"خطأ!\");\n} catch (const std::exception& e) {\n    std::cout << e.what();\n}", "ماذا تطبع e.what()؟", "خطأ!", "خطأ!", "تأكد من أنك قمت بطباعة الرسالة باستخدام std::cout."}
            }
        },
        { // Advanced
            "متقدم 👨‍🏫",
            {
                {"الكائنات والبرمجة الكائنية\nالكائنات تجمع البيانات والدوال.", "class Person {\npublic:\n    std::string name;\n    void say_hello() {\n        std::cout << \"مرحباً، أنا \" << name << std::endl;\n    }\n};", "كيف تستدعي say_hello على كائن p؟", "p.say_hello();", "p.say_hello();", "تأكد من أنك قمت بطباعة الرسالة باستخدام std::cout."},
                {"المؤشرات والذاكرة\nالمؤشرات تخزن عناوين المتغيرات.", "int x = 10;\nint* p = &x;\nstd::cout << *p; // يطبع 10", "ماذا يطبع *p؟", "10", "10", "تأكد من أنك قمت بطباعة القيمة باستخدام std::cout."},
                {"التعامل مع الملفات\nاقرأ/اكتب الملفات باستخدام fstream.", "#include <fstream>\nstd::ofstream out(\"file.txt\");\nout << \"Hello\";\nout.close();", "أي ترويسة تحتاجها للتعامل مع الملفات؟", "<fstream>", "<fstream>", "تأكد من أنك قمت بإضافة #include <fstream>."},
                {"مكتبة القوالب القياسية STL\nتوفر حاويات مفيدة.", "#include <vector>\nstd::vector<int> v = {1,2,3};\nv.push_back(4);", "كيف تضيف عنصراً إلى vector؟", "v.push_back(value);", "v.push_back(value);", "تأكد من أنك قمت بإضافة v.push_back(value);."},
                {"مشروع صغير\nاستخدم ما تعلمته!\nاكتب برنامجاً يطلب 3 أرقام ويطبع مجموعها.", "#include <iostream>\nint main() {\n    int a, b, c;\n    std::cin >> a >> b >> c;\n    std::cout << (a + b + c);\n    return 0;\n}", "ماذا يفعل هذا البرنامج؟", "يقرأ 3 أرقام ويطبع مجموعها.", "يقرأ 3 أرقام ويطبع مجموعها.", "تأكد من أنك قمت بطباعة النتيجة باستخدام std::cout."}
            }
        }
    }
};

// --- Helper Functions ---
void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void print_centered(const std::string& text) {
    // Simple print, can be improved for true centering
    std::cout << text << std::endl;
}

// Typing animation utility function
void type_text(const std::string& text, int delay_ms = 25) {
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
    }
    std::cout << std::endl;
}

// Helper to get current date as string (YYYY-MM-DD)
std::string get_current_date() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    char buf[11];
    snprintf(buf, sizeof(buf), "%04d-%02d-%02d", now->tm_year + 1900, now->tm_mon + 1, now->tm_mday);
    return std::string(buf);
}

// Helper to get current week number (ISO week)
int get_week_number() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    char buf[5];
    strftime(buf, sizeof(buf), "%W", now);
    return atoi(buf);
}

// Helper to get days between two dates (YYYY-MM-DD)
int days_between(const std::string& d1, const std::string& d2) {
    std::tm tm1 = {}, tm2 = {};
    int year1, month1, day1, year2, month2, day2;
    sscanf(d1.c_str(), "%d-%d-%d", &year1, &month1, &day1);
    sscanf(d2.c_str(), "%d-%d-%d", &year2, &month2, &day2);
    tm1.tm_year = year1 - 1900;
    tm1.tm_mon = month1 - 1;
    tm1.tm_mday = day1;
    tm2.tm_year = year2 - 1900;
    tm2.tm_mon = month2 - 1;
    tm2.tm_mday = day2;
    time_t t1 = mktime(&tm1);
    time_t t2 = mktime(&tm2);
    return (int)std::difftime(t2, t1) / (60 * 60 * 24);
}

// Progress save/load helpers
void save_progress(int lang, int level, int lesson, int xp, int bookmark, int daily_goal, int daily_progress, const std::string& last_goal_date, int total_lessons_completed, int total_xp, int sessions_count, const std::string& last_seen_date, int session_counter, int weekly_lessons, int weekly_xp, int weekly_sessions, int current_week) {
    std::ofstream out("progress.txt");
    if (out) {
        out << lang << ' ' << level << ' ' << lesson << ' ' << xp << ' ' << bookmark << ' ' << daily_goal << ' ' << daily_progress << ' ' << last_goal_date << ' ' << total_lessons_completed << ' ' << total_xp << ' ' << sessions_count << ' ' << last_seen_date << ' ' << session_counter << ' ' << weekly_lessons << ' ' << weekly_xp << ' ' << weekly_sessions << ' ' << current_week << std::endl;
    }
}

bool load_progress(int &lang, int &level, int &lesson, int &xp, int &bookmark, int &daily_goal, int &daily_progress, std::string& last_goal_date, int &total_lessons_completed, int &total_xp, int &sessions_count, std::string& last_seen_date, int &session_counter, int &weekly_lessons, int &weekly_xp, int &weekly_sessions, int &current_week) {
    std::ifstream in("progress.txt");
    if (in) {
        in >> lang >> level >> lesson >> xp >> bookmark >> daily_goal >> daily_progress >> last_goal_date >> total_lessons_completed >> total_xp >> sessions_count >> last_seen_date >> session_counter >> weekly_lessons >> weekly_xp >> weekly_sessions >> current_week;
        return true;
    }
    return false;
}

void delete_progress() {
    std::remove("progress.txt");
}

// Notes system helpers
void save_note(int lang, int level, int lesson, const std::string& note) {
    std::ofstream out("notes.txt", std::ios::app);
    if (out) {
        out << get_current_date() << " | Lang:" << lang << " | Level:" << level << " | Lesson:" << (lesson + 1) << " | " << note << std::endl;
    }
}

void display_notes() {
    std::ifstream in("notes.txt");
    if (!in) {
        type_text("No notes found.", 20);
        return;
    }
    std::string line;
    type_text("\n📝 Your Notes:", 25);
    type_text("================", 10);
    while (std::getline(in, line)) {
        std::cout << line << std::endl;
    }
    type_text("================", 10);
}

// Automatic backup helper
void create_backup() {
    std::ifstream src("progress.txt");
    std::ofstream dst("progress_backup.txt");
    if (src && dst) {
        dst << src.rdbuf();
    }
}

// Weekly statistics helper
void display_weekly_stats(int weekly_lessons, int weekly_xp, int weekly_sessions) {
    type_text("\033[1;36m📊 Weekly Statistics Summary\033[0m", 25);
    type_text("================", 10);
    type_text("✅ Total Lessons Completed: " + std::to_string(weekly_lessons), 20);
    type_text("🎯 Total XP: " + std::to_string(weekly_xp), 20);
    type_text("📅 Number of Sessions: " + std::to_string(weekly_sessions), 20);
    if (weekly_sessions > 0) {
        double avg_lessons = (double)weekly_lessons / weekly_sessions;
        std::stringstream ss;
        ss << std::fixed << std::setprecision(1) << avg_lessons;
        type_text("📈 Average Lessons Per Session: " + ss.str(), 20);
    }
    type_text("================", 10);
}

// Instructor mode helper
bool instructor_mode_edit(Localization* loc, int level, int lesson) {
    type_text("\033[1;33m" + loc->instructor_mode + "\033[0m", 25);
    std::cout << loc->instructor_password;
    std::string password;
    std::getline(std::cin, password);
    
    if (password != "instructor123") {
        type_text("\033[31m❌ Incorrect password!\033[0m", 20);
        return false;
    }
    
    type_text("\033[32m✅ Access granted!\033[0m", 20);
    type_text("What would you like to edit?", 20);
    type_text("1) Explanation", 15);
    type_text("2) Code", 15);
    type_text("3) Challenge", 15);
    type_text("4) Solution", 15);
    type_text("5) Cancel", 15);
    std::string choice;
    std::getline(std::cin, choice);
    
    if (choice == "5") return false;
    
    type_text("Enter new content:", 20);
    std::string new_content;
    std::getline(std::cin, new_content);
    
    if (choice == "1") loc->levels[level].lessons[lesson].explanation = new_content;
    else if (choice == "2") loc->levels[level].lessons[lesson].code = new_content;
    else if (choice == "3") loc->levels[level].lessons[lesson].challenge = new_content;
    else if (choice == "4") loc->levels[level].lessons[lesson].solution = new_content;
    
    type_text("\033[32m✅ Content updated!\033[0m", 20);
    return true;
}

// Smart reminder helper
void show_reminder(const std::string& last_seen_date, Localization* loc) {
    std::string today = get_current_date();
    int days = days_between(last_seen_date, today);
    if (days > 2) {
        std::string message = loc->reminder_message;
        size_t pos = message.find("{days}");
        if (pos != std::string::npos) {
            message.replace(pos, 6, std::to_string(days));
        }
        std::cout << "\033[1;33m" << message << "\033[0m\n";
        std::cout << "Press Enter to continue...";
        std::cin.get();
    }
}

// Helper to run end-of-level quiz
void run_end_of_level_quiz(const Level& level, int& xp, int& total_xp) {
    clear_screen();
    type_text("\033[1;36m===== End-of-Level Quiz =====\033[0m", 25);
    int num_questions = std::min(5, (int)level.lessons.size());
    int correct = 0;
    for (int i = 0; i < num_questions; ++i) {
        type_text("Q" + std::to_string(i+1) + ": " + level.lessons[i].challenge, 20);
        std::cout << "Your answer: ";
        std::string answer;
        std::getline(std::cin, answer);
        auto trim = [](std::string s) { size_t f = s.find_first_not_of(" \t\n\r"); size_t l = s.find_last_not_of(" \t\n\r"); return (f == std::string::npos) ? "" : s.substr(f, l - f + 1); };
        auto lower = [](std::string s) { for (auto& c : s) c = tolower(c); return s; };
        std::string correct_ans = level.lessons[i].solution;
        if (lower(trim(answer)) == lower(trim(correct_ans))) {
            type_text("\033[32mCorrect!\033[0m", 15);
            ++correct;
            xp += 5;
            total_xp += 5;
        } else {
            type_text("\033[31mIncorrect.\033[0m Solution: " + correct_ans, 20);
        }
    }
    type_text("\n\033[1;36mFinal Score: " + std::to_string(correct) + "/" + std::to_string(num_questions) + "\033[0m", 25);
    if (correct == num_questions) type_text("\033[32mGreat job!\033[0m", 20);
    else if (correct >= num_questions/2) type_text("\033[33mGood effort!\033[0m", 20);
    else type_text("\033[31mKeep practicing!\033[0m", 20);
    std::cout << "\nType retry to retake the quiz, or press Enter to continue: ";
    std::string retry;
    std::getline(std::cin, retry);
    if (retry == "retry") run_end_of_level_quiz(level, xp, total_xp);
}

// Helper to import lesson from file
bool import_lesson(const std::string& filename, Level& level) {
    std::ifstream in(filename);
    if (!in) return false;
    std::string title, explanation, code, challenge, solution, output, hint;
    std::getline(in, title);
    std::getline(in, explanation);
    std::getline(in, code);
    std::getline(in, challenge);
    std::getline(in, solution);
    std::getline(in, output);
    std::getline(in, hint);
    Lesson l;
    l.explanation = title + "\n" + explanation;
    l.code = code;
    l.challenge = challenge;
    l.solution = solution;
    l.expected_output = output;
    l.hint = hint;
    l.related_title = "";
    l.related_level = "";
    level.lessons.push_back(l);
    return true;
}

// --- Main Interactive Logic ---
int main() {
    // std::locale::global(std::locale("")); // Removed to avoid Windows locale error
    // std::wcout.imbue(std::locale()); // Not needed
    int xp = 0, bookmark = 0, daily_goal = 3, daily_progress = 0;
    int total_lessons_completed = 0, total_xp = 0, sessions_count = 0;
    int session_counter = 0, weekly_lessons = 0, weekly_xp = 0, weekly_sessions = 0;
    int current_week = get_week_number();
    std::string last_goal_date = get_current_date();
    std::string last_seen_date = get_current_date();
    Localization* loc = &en;
    int lang = 1;
    int level = 0;
    int lesson = 0;
    bool in_review_mode = false;
    bool instructor_mode_active = false;

    // --- Progress Load Option ---
    bool has_progress = false;
    int saved_lang = 1, saved_level = 0, saved_lesson = 0, saved_xp = 0, saved_bookmark = 0, saved_daily_goal = 3, saved_daily_progress = 0, saved_total_lessons_completed = 0, saved_total_xp = 0, saved_sessions_count = 0;
    int saved_session_counter = 0, saved_weekly_lessons = 0, saved_weekly_xp = 0, saved_weekly_sessions = 0, saved_current_week = 0;
    std::string saved_last_goal_date, saved_last_seen_date;
    if (load_progress(saved_lang, saved_level, saved_lesson, saved_xp, saved_bookmark, saved_daily_goal, saved_daily_progress, saved_last_goal_date, saved_total_lessons_completed, saved_total_xp, saved_sessions_count, saved_last_seen_date, saved_session_counter, saved_weekly_lessons, saved_weekly_xp, saved_weekly_sessions, saved_current_week)) {
        has_progress = true;
        // Check if date changed for daily goal
        std::string today = get_current_date();
        if (saved_last_goal_date != today) {
            saved_daily_progress = 0;
            saved_last_goal_date = today;
        }
        
        // Check if week changed for weekly stats
        int this_week = get_week_number();
        if (saved_current_week != this_week) {
            saved_weekly_lessons = 0;
            saved_weekly_xp = 0;
            saved_weekly_sessions = 0;
            saved_current_week = this_week;
        }
        
        lang = saved_lang;
        level = saved_level;
        lesson = saved_lesson;
        xp = saved_xp;
        bookmark = saved_bookmark;
        daily_goal = saved_daily_goal;
        daily_progress = saved_daily_progress;
        last_goal_date = saved_last_goal_date;
        total_lessons_completed = saved_total_lessons_completed;
        total_xp = saved_total_xp;
        sessions_count = saved_sessions_count + 1;
        last_seen_date = today;
        session_counter = saved_session_counter + 1;
        weekly_sessions++;
        weekly_lessons = saved_weekly_lessons;
        weekly_xp = saved_weekly_xp;
        weekly_sessions = saved_weekly_sessions;
        current_week = saved_current_week;
        
        // Show smart reminder
        show_reminder(saved_last_seen_date, loc);
        
        // Automatic backup every 3 sessions
        if (session_counter % 3 == 0) {
            create_backup();
            std::cout << "\033[32m" << loc->backup_created << "\033[0m\n";
        }
        
        // Weekly statistics every 7 sessions
        if (session_counter % 7 == 0) {
            display_weekly_stats(weekly_lessons, weekly_xp, weekly_sessions);
            std::cout << "Press Enter to continue...";
            std::cin.get();
        }
    } else {
        // First run: ask for daily goal
        clear_screen();
        std::cout << "Set your daily lesson goal (default 3): ";
        std::string input_goal;
        std::getline(std::cin, input_goal);
        if (!input_goal.empty()) {
            try { daily_goal = std::stoi(input_goal); } catch (...) { daily_goal = 3; }
        }
        last_goal_date = get_current_date();
        last_seen_date = last_goal_date;
        sessions_count = 1;
        session_counter = 1;
        current_week = get_week_number();
    }

    // --- Language Selection ---
    if (!has_progress || (lang != 1 && lang != 2)) {
        while (true) {
            clear_screen();
            print_centered(loc->select_language);
            std::string input;
            std::getline(std::cin, input);
            if (input == "1") { loc = &en; lang = 1; break; }
            if (input == "2") { loc = &ar; lang = 2; break; }
        }
        
        // Show welcome message with typing animation
        clear_screen();
        type_text(loc->welcome_message, 30);
        std::cout << "\nPress Enter to continue...";
        std::cin.get();
    }

    // --- Level Selection ---
    if (!has_progress || (level < 0 || level > 2)) {
        while (true) {
            clear_screen();
            print_centered(loc->select_level);
            std::string input;
            std::getline(std::cin, input);
            if (input == "1") { level = 0; break; }
            if (input == "2") { level = 1; break; }
            if (input == "3") { level = 2; break; }
        }
    }

    // --- Mode Selection ---
    bool challenge_mode = false;
    clear_screen();
    std::cout << "Choose a mode:\n1) Training Mode\n2) Challenge Mode\n";
    std::string mode_input;
    std::getline(std::cin, mode_input);
    if (mode_input == "2") challenge_mode = true;

    // --- Lesson Loop ---
    int lesson_count = loc->levels[level].lessons.size();
    while (true) {
        clear_screen();
        if (challenge_mode) {
            type_text("\033[1m" + loc->lesson_header + std::to_string(lesson + 1) + "/" + std::to_string(lesson_count) + ":\033[0m", 20);
            type_text(loc->challenge_header, 15);
            std::cout << loc->levels[level].lessons[lesson].challenge << std::endl;
            std::cout << "Type your answer (or type skip/back/exit): ";
            std::string answer;
            std::getline(std::cin, answer);
            if (answer == "exit") break;
            if (answer == "back") { if (lesson > 0) lesson--; continue; }
            if (answer == "skip") { if (lesson < lesson_count - 1) lesson++; continue; }
            // Compare answer (case-insensitive, trimmed)
            std::string correct = loc->levels[level].lessons[lesson].solution;
            auto trim = [](std::string s) { size_t f = s.find_first_not_of(" \t\n\r"); size_t l = s.find_last_not_of(" \t\n\r"); return (f == std::string::npos) ? "" : s.substr(f, l - f + 1); };
            auto lower = [](std::string s) { for (auto& c : s) c = tolower(c); return s; };
            if (lower(trim(answer)) == lower(trim(correct))) {
                xp += 10;
                daily_progress++;
                total_xp += 10;
                total_lessons_completed++;
                weekly_xp += 10;
                weekly_lessons++;
                std::cout << "\033[32m✅ Correct! You earned 10 XP! Total: " << xp << "\033[0m\n";
            } else {
                std::cout << "\033[31m❌ Incorrect.\033[0m\n";
                std::cout << "Solution: " << correct << std::endl;
            }
            std::cout << "\033[33m✅ You've completed " << daily_progress << "/" << daily_goal << " of your daily goal!\033[0m\n";
            if (daily_progress >= daily_goal) {
                std::cout << "\033[32m🎉 Daily goal achieved! You’re crushing it!\033[0m\n";
            }
            std::cin.get();
            if (lesson < lesson_count - 1) lesson++;
            save_progress(lang, level, lesson, xp, bookmark, daily_goal, daily_progress, last_goal_date, total_lessons_completed, total_xp, sessions_count, last_seen_date, session_counter, weekly_lessons, weekly_xp, weekly_sessions, current_week);
            continue;
        }
        if (in_review_mode) {
            type_text("\033[1m" + loc->lesson_header + std::to_string(lesson + 1) + "/" + std::to_string(lesson_count) + ":\033[0m", 20);
            // Show only title (first line of explanation), summary, and challenge
            std::string expl = loc->levels[level].lessons[lesson].explanation;
            size_t pos = expl.find('\n');
            std::string title = (pos != std::string::npos) ? expl.substr(0, pos) : expl;
            std::string summary = (pos != std::string::npos) ? expl.substr(pos + 1) : "";
            std::cout << "\033[1;34m" << title << "\033[0m\n";
            if (!summary.empty()) std::cout << summary << "\n";
            type_text(loc->challenge_header, 15);
            std::cout << loc->levels[level].lessons[lesson].challenge << std::endl;
            std::cout << "[review mode] Type next, back, repeat, exit to leave review\n";
        } else {
            type_text(loc->lesson_header + std::to_string(lesson + 1) + "/" + std::to_string(lesson_count) + ":", 20);
            std::cout << loc->levels[level].lessons[lesson].explanation << std::endl;
            type_text(loc->code_header, 15);
            std::cout << loc->levels[level].lessons[lesson].code << std::endl;
            type_text(loc->challenge_header, 15);
            std::cout << loc->levels[level].lessons[lesson].challenge << std::endl;
            
            // Show related lesson suggestion if available
            if (!loc->levels[level].lessons[lesson].related_title.empty() && !loc->levels[level].lessons[lesson].related_level.empty()) {
                std::cout << "\033[1;35m" << loc->related_topic << "\"" << loc->levels[level].lessons[lesson].related_title << "\" from " << loc->levels[level].lessons[lesson].related_level << "\033[0m\n";
            }
            
            std::cout << loc->commands_hint << std::endl;
        }
        std::cout << std::endl << loc->prompt_command;
        std::string input;
        std::getline(std::cin, input);
        // Import command
        if ((lang == 2 && input == "استيراد") || (lang == 1 && input == "import")) {
            std::cout << "Enter filename to import: ";
            std::string fname;
            std::getline(std::cin, fname);
            if (import_lesson(fname, loc->levels[level])) {
                std::cout << "\033[32mLesson imported successfully!\033[0m\n";
            } else {
                std::cout << "\033[31mFailed to import lesson.\033[0m\n";
            }
            std::cin.get();
            continue;
        }
        // Save progress after each lesson
        save_progress(lang, level, lesson, xp, bookmark, daily_goal, daily_progress, last_goal_date, total_lessons_completed, total_xp, sessions_count, last_seen_date, session_counter, weekly_lessons, weekly_xp, weekly_sessions, current_week);
        if (lang == 2) {
            // Arabic commands
            if (input == "مراجعة") { in_review_mode = true; continue; }
            if (in_review_mode) {
                if (input == "التالي") {
                    if (lesson < lesson_count - 1) {
                        lesson++;
                        xp += 10;
                        daily_progress++;
                        total_xp += 10;
                        total_lessons_completed++;
                        weekly_xp += 10;
                        weekly_lessons++;
                        std::cout << "\033[32m✅ لقد حصلت على 10 نقطة خبرة! المجموع: " << xp << "\033[0m\n";
                        std::cout << "\033[33m✅ أنجزت " << daily_progress << "/" << daily_goal << " من هدفك اليومي!\033[0m\n";
                        if (daily_progress >= daily_goal) {
                            std::cout << "\033[32m🎉 لقد حققت هدفك اليومي! أنت رائع!\033[0m\n";
                        }
                        std::cin.get();
                    } else { std::cout << loc->next_last << std::endl; std::cin.get(); }
                } else if (input == "السابق") {
                    if (lesson > 0) lesson--;
                    else { std::cout << loc->back_first << std::endl; std::cin.get(); }
                } else if (input == "إعادة") {
                    continue;
                } else if (input == "خروج") {
                    in_review_mode = false;
                    continue;
                }
            }
            if (input == "التالي") {
                if (lesson < lesson_count - 1) {
                    lesson++;
                    xp += 10;
                    daily_progress++;
                    total_xp += 10;
                    total_lessons_completed++;
                    std::cout << "\033[32m✅ لقد حصلت على 10 نقطة خبرة! المجموع: " << xp << "\033[0m\n";
                    std::cout << "\033[33m✅ أنجزت " << daily_progress << "/" << daily_goal << " من هدفك اليومي!\033[0m\n";
                    if (daily_progress >= daily_goal) {
                        std::cout << "\033[32m🎉 لقد حققت هدفك اليومي! أنت رائع!\033[0m\n";
                    }
                    std::cin.get();
                } else { std::cout << loc->next_last << std::endl; std::cin.get(); }
            } else if (input == "السابق") {
                if (lesson > 0) lesson--;
                else { std::cout << loc->back_first << std::endl; std::cin.get(); }
            } else if (input == "إعادة") {
                continue;
            } else if (input == "الكود") {
                clear_screen();
                type_text(loc->code_header, 15);
                std::cout << loc->levels[level].lessons[lesson].code << std::endl;
                std::cin.get();
            } else if (input == "الحل") {
                clear_screen();
                type_text(loc->solution_header, 15);
                std::cout << loc->levels[level].lessons[lesson].solution << std::endl;
                std::cin.get();
            } else if (input == "ملاحظة") {
                std::cout << loc->note_prompt;
                std::string note;
                std::getline(std::cin, note);
                save_note(lang, level, lesson, note);
                std::cout << "\033[32m" << loc->note_saved << "\033[0m\n";
                std::cin.get();
            } else if (input == "ملاحظات") {
                display_notes();
                std::cin.get();
            } else if (input == "علامة") {
                bookmark = lesson;
                std::cout << "\033[32m" << loc->bookmark_saved << (lesson + 1) << "\033[0m\n";
                std::cin.get();
            } else if (input == "اذهب") {
                if (bookmark >= 0 && bookmark < lesson_count) {
                    lesson = bookmark;
                    std::cout << "\033[32m" << loc->bookmark_loaded << (lesson + 1) << "\033[0m\n";
                } else {
                    std::cout << "\033[31m❌ No bookmark set!\033[0m\n";
                }
                std::cin.get();
            } else if (input == "وضع") {
                if (instructor_mode_edit(loc, level, lesson)) {
                    instructor_mode_active = true;
                }
                std::cin.get();
            } else if (input == "خروج") {
                std::cout << loc->goodbye << std::endl;
                break;
            } else {
                std::cout << loc->invalid_command << std::endl;
                std::cin.get();
            }
        } else {
            // English commands
            if (input == "review") { in_review_mode = true; continue; }
            if (in_review_mode) {
                if (input == "next") {
                    if (lesson < lesson_count - 1) {
                        lesson++;
                        xp += 10;
                        daily_progress++;
                        total_xp += 10;
                        total_lessons_completed++;
                        weekly_xp += 10;
                        weekly_lessons++;
                        std::cout << "\033[32m✅ You earned 10 XP! Total: " << xp << "\033[0m\n";
                        std::cout << "\033[33m✅ You've completed " << daily_progress << "/" << daily_goal << " of your daily goal!\033[0m\n";
                        if (daily_progress >= daily_goal) {
                            std::cout << "\033[32m🎉 Daily goal achieved! You’re crushing it!\033[0m\n";
                        }
                        std::cin.get();
                    } else { std::cout << loc->next_last << std::endl; std::cin.get(); }
                } else if (input == "back") {
                    if (lesson > 0) lesson--;
                    else { std::cout << loc->back_first << std::endl; std::cin.get(); }
                } else if (input == "repeat") {
                    continue;
                } else if (input == "exit") {
                    in_review_mode = false;
                    continue;
                }
            }
            if (input == "next") {
                if (lesson < lesson_count - 1) {
                    lesson++;
                    xp += 10;
                    daily_progress++;
                    total_xp += 10;
                    total_lessons_completed++;
                    weekly_xp += 10;
                    weekly_lessons++;
                    std::cout << "\033[32m✅ You earned 10 XP! Total: " << xp << "\033[0m\n";
                    std::cout << "\033[33m✅ You've completed " << daily_progress << "/" << daily_goal << " of your daily goal!\033[0m\n";
                    if (daily_progress >= daily_goal) {
                        std::cout << "\033[32m🎉 Daily goal achieved! You’re crushing it!\033[0m\n";
                    }
                    std::cin.get();
                } else { std::cout << loc->next_last << std::endl; std::cin.get(); }
            } else if (input == "back") {
                if (lesson > 0) lesson--;
                else { std::cout << loc->back_first << std::endl; std::cin.get(); }
            } else if (input == "repeat") {
                continue;
            } else if (input == "code") {
                clear_screen();
                type_text(loc->code_header, 15);
                std::cout << loc->levels[level].lessons[lesson].code << std::endl;
                std::cin.get();
            } else if (input == "solution") {
                clear_screen();
                type_text(loc->solution_header, 15);
                std::cout << loc->levels[level].lessons[lesson].solution << std::endl;
                std::cin.get();
            } else if (input == "note") {
                std::cout << loc->note_prompt;
                std::string note;
                std::getline(std::cin, note);
                save_note(lang, level, lesson, note);
                std::cout << "\033[32m" << loc->note_saved << "\033[0m\n";
                std::cin.get();
            } else if (input == "notes") {
                display_notes();
                std::cin.get();
            } else if (input == "bookmark") {
                bookmark = lesson;
                std::cout << "\033[32m" << loc->bookmark_saved << (lesson + 1) << "\033[0m\n";
                std::cin.get();
            } else if (input == "goto") {
                if (bookmark >= 0 && bookmark < lesson_count) {
                    lesson = bookmark;
                    std::cout << "\033[32m" << loc->bookmark_loaded << (lesson + 1) << "\033[0m\n";
                } else {
                    std::cout << "\033[31m❌ No bookmark set!\033[0m\n";
                }
                std::cin.get();
            } else if (input == "mode") {
                if (instructor_mode_edit(loc, level, lesson)) {
                    instructor_mode_active = true;
                }
                std::cin.get();
            } else if (input == "exit") {
                std::cout << loc->goodbye << std::endl;
                break;
            } else {
                std::cout << loc->invalid_command << std::endl;
                std::cin.get();
            }
        }
        // End-of-level evaluation and quiz
        if (!in_review_mode && !challenge_mode && lesson == lesson_count - 1) {
            type_text("\033[1;35m🎓 Level Completed: " + loc->levels[level].name + "\033[0m", 25);
            type_text("✅ You answered " + std::to_string(lesson_count) + "/" + std::to_string(lesson_count) + " challenges", 20);
            type_text("🎯 XP Earned: " + std::to_string(xp), 20);
            type_text("🏆 Great progress!", 20);
            std::cout << "\nPress Enter to take the end-of-level quiz...\n";
            std::cin.get();
            run_end_of_level_quiz(loc->levels[level], xp, total_xp);
            std::cout << "\nType retry to repeat the level, or next to proceed: ";
            std::string end_input;
            std::getline(std::cin, end_input);
            if (end_input == "retry") { lesson = 0; continue; }
            if (end_input == "next") break;
        }
    }
    return 0;
} 

















