using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;

public class readFile : MonoBehaviour
{
    public string readPath;
    public Hashtable _params;
    void Awake()
    {
        _params = new Hashtable();
        readPath = Application.dataPath + "/Tracker/params";
        ReadParams(readPath);
        //this.gameObject.GetComponent<writeFile>().WriteParams(readPath);
        string rp = Application.dataPath + "/Tracker/Output/run.1/run.1.stepsummary";
        ReadTimestep(rp);
    }

    public void ReadParams(string path)
    {
        StreamReader sr = new StreamReader(path, Encoding.Default);
        string line;
        while ((line = sr.ReadLine()) != null)          //Read from top to bottom, then put variable name as key, value as value to a hashtable.
        {
            BuildParams(line);
        }
        //Debug.Log("Rerun : " + _params["Rerun"]);
        sr.Close();
    }

    public void BuildParams(string line)
    {
        string[] param = Regex.Split(line,"\\s+",RegexOptions.IgnoreCase);
        _params.Add(param[0],param[1]);
        //Debug.Log(param[0] + " " + param[1]);
    }



    public ArrayList timeSteps;
    public void ReadTimestep(string path)
    {
        StreamReader sr = new StreamReader(path, Encoding.Default);
        timeSteps = new ArrayList();
        string line;
        while ((line = sr.ReadLine()) != null)          //Read from top to bottom, then put variable name as key, value as value to a hashtable.
        {
            BuildTimestep(line);
        }
        //foreach (TimeStep t1 in timeSteps)
        //{
        //    Debug.Log(t1.time+" "+t1.target_x+" "+t1.target_y+" "+t1.tracker_x+" "+t1.tracker_y);
        //}
        //Debug.Log("Rerun : " + _params["Rerun"]);
        sr.Close();
    }

    public void BuildTimestep(string line)
    {
        string[] ts = Regex.Split(line, "\\s+", RegexOptions.IgnoreCase);
        int step = 3;
        TimeStep t1 = new TimeStep(int.Parse(ts[2]), step*float.Parse(ts[4]), step * float.Parse(ts[5]), step * float.Parse(ts[7]), step * float.Parse(ts[8]));
        timeSteps.Add(t1);
        //Debug.Log(param[0] + " " + param[1]);
    }
}
