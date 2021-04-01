using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ioPath : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        string s;
        s = "System.IO.Directory.GetCurrentDirectory(): " + System.IO.Directory.GetCurrentDirectory()+ "\n";
        s += "Application.dataPath: " + Application.dataPath + "\n";
        s += "System.AppDomain.CurrentDomain.BaseDirectory: " + System.AppDomain.CurrentDomain.BaseDirectory + "\n";
        s += "Application.streamingAssetsPath: " + Application.streamingAssetsPath + "\n";
        s += "Application.persistentDataPath: " + Application.persistentDataPath + "\n"; 
        gameObject.GetComponent<Text>().text = s; 
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
