﻿using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;
using UnityEngine;
using UnityEngine.UI;

public class runButton : MonoBehaviour
{
    [SerializeField] GameObject[] inputFields;
    [SerializeField] GameObject[] dropdowns;
    //[SerializeField] Camera cam;
    public string readPath;
    public Hashtable _params;
    public string run_num;
    public string runNumPath;
    // Start is called before the first frame update
    public GameObject mainCamera;
    void Start()
    {
    
        _params = new Hashtable();
        readPath = Application.dataPath + "/Tracker/params";
        ReadParams(readPath);


        runNumPath = Application.dataPath + "/Tracker/run.num";
        ReadRunNum(runNumPath);

    }



    public void ReadRunNum(string path)
    {
        StreamReader sr = new StreamReader(path, Encoding.Default);
        string line;
        if ((line = sr.ReadLine()) != null)
        {
            run_num = line;
        }
        sr.Close();
    }



    public void ReadParams(string path)
    {
        StreamReader sr = new StreamReader(readPath, Encoding.Default);
        string line;
        while ((line = sr.ReadLine()) != null)          //Read from top to bottom, then put variable name as key, value as value to a hashtable.
        {
            BuildParams(line);
        }
        Debug.Log("-------------------complete--------------");
        //Debug.Log("Rerun : " + _params["Rerun"]);
        sr.Close();
    }

    public void BuildParams(string line)
    {
        string[] param = Regex.Split(line, "\\s+", RegexOptions.IgnoreCase);
        _params.Add(param[0], param[1]);
        //Debug.Log("reading" + param[0] + " " + param[1]);
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void getFieldText()
    {
        string line;
        
        for (int i = 0; i<inputFields.Length; i++)
        {
            string value = inputFields[i].GetComponent<InputField>().text;
            GameObject parent = inputFields[i].transform.parent.gameObject;
            string key = parent.GetComponent<Text>().text;
            //Debug.Log(key+" "+ value);
            if (_params.ContainsKey(key))
            {
                if (!_params[key].Equals(value))
                {
                    _params[key] = value;
                    Debug.Log("the modified key is:" + key + " to value:" + value);
                }
                
            }
        }

        for (int i = 0; i < dropdowns.Length; i++)
        {
            Dropdown dd = dropdowns[i].GetComponent<Dropdown>();
            string value = dd.options[dd.value].text;
            GameObject parent = dropdowns[i].transform.parent.gameObject;
            string key = parent.GetComponent<Text>().text;
            //Debug.Log(key + " " + value);
            if (_params.ContainsKey(key))
            {
                if (!_params[key].Equals(value))
                {
                    _params[key] = value;
                    Debug.Log("the modified key is:" + key + " to value:" + value);
                }
            }
        }

        try
        {
            System.Collections.IDictionaryEnumerator enumerator = _params.GetEnumerator();
            FileStream fs = new FileStream(readPath, FileMode.Create);
            StreamWriter sw = new StreamWriter(fs);
            while (enumerator.MoveNext())
            {
                line = enumerator.Key + "     " + enumerator.Value + "\r\n";
                //Debug.Log(line);
                sw.Write(line);
                sw.Flush();
                
            }

            sw.Close();
            fs.Close();
            Debug.Log("-------------------------");
            mainCamera = GameObject.Find("Main Camera");
            mainCamera.GetComponent<test>().run();
        }
        catch (IOException)
        {
            Debug.Log("The params file may opened by another program!");
        }
        ReadRunNum(runNumPath);
    }


}
