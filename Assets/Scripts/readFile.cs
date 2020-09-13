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
        ReadParams(readPath);
        //this.gameObject.GetComponent<writeFile>().WriteParams(readPath);
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
}
