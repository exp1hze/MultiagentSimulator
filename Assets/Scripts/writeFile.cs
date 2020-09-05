using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;
using System.Text;
public class writeFile : MonoBehaviour
{
    Hashtable _params;
    void Start()
    {
        
    }

    public void WriteParams(string path)
    {
        string line;
        _params = this.gameObject.GetComponent<readFile>()._params;
        System.Collections.IDictionaryEnumerator enumerator = _params.GetEnumerator();
        try
        {
            FileStream fs = new FileStream(path, FileMode.Create);
            StreamWriter sw = new StreamWriter(fs);
            while (enumerator.MoveNext())
            {
                line = enumerator.Key + "     " + enumerator.Value + "\r\n";
                Debug.Log(line);
                sw.Write(line);
                sw.Flush();
            }

            sw.Close();
            fs.Close();
        }
        catch (IOException)
        {
            Debug.Log("The params file may opened by another program!");
        }

    }
}
