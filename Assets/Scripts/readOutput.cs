using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;

public class readOutput : MonoBehaviour
{
    public string readPath;
    void Start()
    {
        readPath = Application.dataPath + "/Tracker/Output";

    }

    public void ReadOutputWithNum(string num)
    {
        readPath += "/run." + num + ".";
        ReadFromRandom(readPath + "random");
        ReadFromParams(readPath + "params");
        ReadFromInitpop(readPath + "initpop");
        ReadFromgGnu(readPath + "gnu");
        ReadFromStepsummary(readPath + "stepsummary");
        ReadFromStepsummary(readPath + "stepsummary");
        ReadFromStepeastwest(readPath + "stepeastwest");
        ReadFromStepagentaction(readPath + "stepagentaction");
        ReadFromStepagentactionxyz(readPath + "stepagentactionxyz");
        ReadFromFinalstats(readPath + "finalstats");
        ReadFromFinalagent(readPath + "finalagent");
        ReadFromSteptargetpath(readPath + "steptargetpath");
        ReadFromSteptrackerpath(readPath + "steptrackerpath");
    }

    public string random;                                           //using a string to store the random number.
    public void ReadFromRandom(string path)
    {
        StreamReader sr = new StreamReader(path, Encoding.Default);
        string line;
        if ((line = sr.ReadLine()) != null)
        {
            random = line;
        }
        sr.Close();
    }

    public Hashtable _params;
    public void ReadFromParams(string path)                         //using a hashtable to store params.
    {
        StreamReader sr = new StreamReader(path, Encoding.Default);
        string line;
        while ((line = sr.ReadLine()) != null)
        {
            string[] param = Regex.Split(line, "\\s+", RegexOptions.IgnoreCase);
            _params.Add(param[0], param[2]);                        // "Run_num = 1" split into 3 strings, we just need first string as name and third string as value.
        }
        while ((line = sr.ReadLine()) != null)
        {
            string[] param = Regex.Split(line, "\\s+", RegexOptions.IgnoreCase);
            if(param.Length == 3)
            {
                _params.Add(param[0], param[2]);
            }                    
        }
        while ((line = sr.ReadLine()) != null)
        {
            string[] param = Regex.Split(line, "\\s+", RegexOptions.IgnoreCase);
            if (param.Length == 3)
            {
                _params.Add(param[0], param[2]);
            }
        }

        sr.Close();
    }

    public void ReadFromInitpop(string path)
    {
        StreamReader sr = new StreamReader(path, Encoding.Default);
        string line;
        sr.Close();
    }

    public void ReadFromgGnu(string path)
    {
        StreamReader sr = new StreamReader(path, Encoding.Default);
        string line;
        sr.Close();
    }

    public void ReadFromStepsummary(string path)
    {
        StreamReader sr = new StreamReader(path, Encoding.Default);
        string line;
        sr.Close();
    }

    public void ReadFromStepnorthsouth(string path)
    {
        StreamReader sr = new StreamReader(path, Encoding.Default);
        string line;
    }

    public void ReadFromStepeastwest(string path)
    {
        StreamReader sr = new StreamReader(path, Encoding.Default);
        string line;
        sr.Close();
    }

    public void ReadFromStepagentaction(string path)
    {
        StreamReader sr = new StreamReader(path, Encoding.Default);
        string line;
        sr.Close();
    }

    public void ReadFromStepagentactionxyz(string path)
    {
        StreamReader sr = new StreamReader(path, Encoding.Default);
        string line;
        sr.Close();
    }

    public void ReadFromFinalstats(string path)
    {
        StreamReader sr = new StreamReader(path, Encoding.Default);
        string line;
        sr.Close();
    }

    public void ReadFromFinalagent(string path)
    {
        StreamReader sr = new StreamReader(path, Encoding.Default);
        string line;
        sr.Close();
    }

    public void ReadFromSteptargetpath(string path)
    {
        StreamReader sr = new StreamReader(path, Encoding.Default);
        string line;
        sr.Close();
    }

    public void ReadFromSteptrackerpath(string path)
    {
        StreamReader sr = new StreamReader(path, Encoding.Default);
        string line;
        sr.Close();
    }
}
