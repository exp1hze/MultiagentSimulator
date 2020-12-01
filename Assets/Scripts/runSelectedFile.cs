using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEngine;
using UnityEngine.UI;
public class runSelectedFile : MonoBehaviour
{
    public Text fileName;

    // Update is called once per frame
    void Update()
    {
        
    }

    public void runASelectedFile()
    {

    }

    public void delete()
    {

        string path= Application.dataPath + "/Tracker/Output/"+fileName.text;

        DirectoryInfo di = new DirectoryInfo(path);
        di.Delete(true);

        Destroy(gameObject);
    }
}
