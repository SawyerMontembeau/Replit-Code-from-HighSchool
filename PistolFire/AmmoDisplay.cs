using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class AmmoDisplay : MonoBehaviour
{
    public GameObject ammoPanel;
    public static int pistolCount = 20;
    // Start is called before the first frame update
    void Start()
    {
       
    }

    // Update is called once per frame
    void Update()
    {
        ammoPanel.GetComponent<Text>().text = "Ammo: " + pistolCount;
    }
}
