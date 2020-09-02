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
    void Start()
    {
        _params = new Hashtable();
        readPath = Application.dataPath + "/Tracker/params";
        Read(readPath);
    }

    public void Read(string path)
    {
        StreamReader sr = new StreamReader(path, Encoding.Default);
        string line;
        while ((line = sr.ReadLine()) != null)
        {
            BuildParams(line);
        }
        Debug.Log("Rerun : " + _params["Rerun"]);
    }

    public void BuildParams(string line)
    {
        string[] param = Regex.Split(line,"\\s+",RegexOptions.IgnoreCase);
        _params.Add(param[0],param[1]);
    }
}
