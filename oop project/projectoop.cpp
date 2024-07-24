#include <iostream>
#include <fstream>
using namespace std;

// Add a new class to handle file operations
class FileHandler
{
public:
    void saveToFile(double aggregate)
    {
        ofstream file("aggregate_data.txt", ios::app); // Open the file in append mode
        if (file.is_open())
        {
            file << aggregate << endl; // Write the aggregate to the file
            file.close();              // Close the file
        }
        else
        {
            cout << "Error: Unable to open file for writing." << endl;
        }
    }

    void loadFromFile()
    {
        ifstream file("aggregate_data.txt"); // Open the file for reading
        double aggregate;

        if (file.is_open())
        {
            cout << "Previous Aggregate Data:" << endl;
            while (file >> aggregate) // Read aggregates from the file
            {
                
                cout << "Your Aggregate is :"<< aggregate << endl;
            }
            file.close(); // Close the file
        }
        else
        {
            cout << "No previous data found." << endl;
        }
    }
};

class MainActivity
{
public:
    MainActivity()
    {
        // Constructor
        cout << "-----------------------------------------------------------" << endl;
        cout << ">>>>    UNIVERSITIES AGGREGATE CALCULATOR    <<<<" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "Choose below Options :" << endl;
        cout << "------------------------------------" << endl;
        cout << "press 1 FAST NU" << endl;
        cout << "press 2 NUST" << endl;
        cout << "press 3 GIKI" << endl;
        cout << "press 4 ETEA Medical " << endl;
        cout << "press 5 Engineering" << endl;
        cout << "------------------------------------" << endl;
        cout << "Enter Your Choice : ";
    }

    ~MainActivity()
    {
        // Destructors
    }
};

class Matric_Fsc_marks
{
protected:
    int obtained_Matric, total_Matric, obatined_Fsc, total_Fsc;
    double matric_Percenatge, fsc_percentage;

public:
    void matricPercentage()
    {
        cout << "Enter Obtained Marks of Matric : ";
        cin >> obtained_Matric;
        cout << "Enter Total Marks of Matric : ";
        cin >> total_Matric;

        try
        {
            if (total_Matric > 0)
            {
                matric_Percenatge = ((obtained_Matric * 100) / total_Matric);
            }
            else
            {
                throw (total_Matric);
            }
        }
        catch (int marks)
        {
            cout << "Warning : You have entered Wrong Marks : " << marks << endl;
        }
    }

    void FscPercentage()
    {
        cout << "Enter Obtained Marks of FSC : ";
        cin >> obatined_Fsc;
        cout << "Enter Total Marks of FSC : ";
        cin >> total_Fsc;

        try
        {
            if (total_Fsc > 0)
            {
                fsc_percentage = ((obatined_Fsc * 100) / total_Fsc);
            }
            else
            {
                throw (total_Fsc);
            }
        }
        catch (int marks)
        {
            cout << "Warning : You entered wrong marks : " << marks << endl;
        }
    }

    virtual double agg()
    {
        cout << "Function for Overriding" << endl;
        return 0.0;
    }
};

class FAST : public Matric_Fsc_marks
{
protected:
    double fastAgg;

public:
    double agg()
    {
        fastAgg = ((matric_Percenatge * 50) / 100) + ((fsc_percentage * 50) / 100);
        cout << "------------------------------------" << endl;
        cout << ">>>>  Your FAST NU Aggregate is: " << fastAgg << endl;
        cout << "According to 2023 Policy" << endl;
        return fastAgg;
    }
};

class NUST : public Matric_Fsc_marks
{
protected:
    int NET;
    double nustAgg, NETpercentage;

public:
    double agg()
    {
        cout << "Enter Your NET marks : ";
        cin >> NET;
        NETpercentage = ((NET * 100) / 200);
        nustAgg = ((matric_Percenatge * 10) / 100) + ((fsc_percentage * 15) / 100) + ((NETpercentage * 75) / 100);
        cout << "------------------------------------" << endl;
        cout << ">>>>  Your NUST Aggregate : " << nustAgg << endl;
        return nustAgg;
    }
};

class GIKI : public Matric_Fsc_marks
{
protected:
    int gikiTest;
    double GIKIAgg, GIKITestPercentage;

public:
    double agg()
    {
        cout << "------------------------------------" << endl;
        cout << "Enter Your GIKI Test marks : ";
        cin >> gikiTest;
        GIKITestPercentage = ((gikiTest * 100) / 200);
        GIKIAgg = ((matric_Percenatge * 5) / 100) + ((fsc_percentage * 10) / 100) + ((GIKITestPercentage * 85) / 100);
        cout << "------------------------------------" << endl;
        cout << ">>>>  Your GIKI Aggregate is : " << GIKIAgg << endl;
        return GIKIAgg;
    }
};

class EMedical : public Matric_Fsc_marks
{
protected:
    int ETEATest;
    double EMAgg, ETestPercentage;

public:
    double agg()
    {
        cout << "------------------------------------" << endl;
        cout << "Enter Your ETEA Medical Test marks : ";
        cin >> ETEATest;
        ETestPercentage = ((ETEATest * 100) / 200);
        EMAgg = ((fsc_percentage * 50) / 100) + ((ETestPercentage * 50) / 100);
        cout << "------------------------------------" << endl;
        cout << ">>>>  Your ETEA Medical Aggregate is : " << EMAgg << endl;
        return EMAgg;
    }
};

class EEngineering : public Matric_Fsc_marks
{
protected:
    int EngrTest;
    double EngrAgg, EngrTesTPercentage;

public:
    double agg()
    {
        cout << "Enter Your ETEA Engineering Test marks : ";
        cin >> EngrTest;
        EngrTesTPercentage = ((EngrTest * 100) / 800);
        EngrAgg = ((matric_Percenatge * 10) / 100) + ((fsc_percentage * 40) / 100) + ((EngrTesTPercentage * 50) / 100);
        cout << "------------------------------------" << endl;
        cout << ">>>>  Your ETEA ENGINEERING Aggregate is : " << EngrAgg << endl;
        return EngrAgg;
    }
};

int main()
{
    FileHandler fileHandler;
    fileHandler.loadFromFile(); // Load previous data if available

    int option;
    FAST F;
    NUST N;
    GIKI G;
    EMedical M;
    EEngineering E;
    char chose;
    int i = 0;

    do
    {
        MainActivity();
        cin >> option;

        ////////////   FAST  /////////
        if (option == 1)
        {
            cout << "------------------------------------" << endl;
            cout << "----- FAST NU Aggregate Calculation -----" << endl;
            cout << endl;
            F.matricPercentage();
            F.FscPercentage();
            double fastAggregate = F.agg();
            fileHandler.saveToFile(fastAggregate); // Save the aggregate to file
        }
        ////////////   NUST   /////////
        else if (option == 2)
        {
            cout << "------------------------------------" << endl;
            cout << "----- NUST Aggregate Calculation -----" << endl;
            cout << endl;
            N.matricPercentage();
            N.FscPercentage();
            double nustAggregate = N.agg();
            fileHandler.saveToFile(nustAggregate); // Save the aggregate to file
        }

        // ... (unchanged)

        cout << "------------------------------------" << endl;
        cout << "To Continue Press 'Y' and for Exit Press 'E'" << endl;
        cin >> chose;
        i++;
    } while (chose == 'y' || chose == 'Y');

    return 0;
}
