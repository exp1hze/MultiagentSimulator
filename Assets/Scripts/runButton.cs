using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;
using UnityEngine;
using UnityEngine.UI;

public class runButton : MonoBehaviour
{
    [SerializeField] GameObject[] inputFields;
    //[SerializeField] Camera cam;
    public string readPath;
    public Hashtable _params;
    // Start is called before the first frame update
    public GameObject mainCamera;
    void Start()
    {
    
        _params = new Hashtable();
        readPath = Application.dataPath + "/Tracker/params";
        ReadParams(readPath);
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
        Debug.Log("reading" + param[0] + " " + param[1]);
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
            Debug.Log(key+" "+ value);
            if (_params.ContainsKey(key))
            {
                _params[key] = value;
                Debug.Log("the modified key is:" + key + " to value:" + value);
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
            mainCamera = GameObject.Find("Main Camera");
            mainCamera.GetComponent<test>().run();
        }
        catch (IOException)
        {
            Debug.Log("The params file may opened by another program!");
        }
    }


}
